
// #include <cstdlib>
#include <cstddef>
#include <iterator>
#include <new>
#include <malloc.h>
#include <iostream>

#define __THROW_BAD_ALLOC \
	std::cerr << "out of memory";

// level1 allocator
template<int inst>
class __malloc_alloc_template {
private:
	static void* oom_malloc(size_t);
	static void* oom_realloc(void*, size_t);
	static void (*__malloc_alloc_oom_handler) ();
	// the function pointer points to the new-handler;
public:
	static void* allocate(size_t n) {
		void* result = malloc(n);
		if(0 == result) result = oom_malloc(n);
		return result;
	}

	static void deallocate(void* p, size_t) {
		free(p);
	}

	static void* reallocate(void* p, size_t, size_t new_sz) {
		void* result = realloc(p, new_sz);
		if(0 == result) result = oom_realloc(p, new_sz);
		return result;
	}

	static void (*set_malloc_handler(void (*f) ())) () {
		// similar to C++ new handler
		void (*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return (old);
		// pass back the old hadnler
	}
};

template<int inst>
void (*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler) () = 0;

// implementation of oom_malloc
template<int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n) {
	void (*my_malloc_handler) ();
	void* result;
	
	for(;;) {
		my_malloc_handler = __malloc_alloc_oom_handler;	// change a name
		if(0 == my_malloc_handler) { __THROW_BAD_ALLOC; }	// no handler
		(*my_malloc_handler) ();	// call the handler, try to free some memory
		result = malloc(n);
		if(result) return result;
	}
}

// implementation of oom_realloc, similar to oom_malloc
template<int inst>
void* __malloc_alloc_template<inst>::oom_realloc(void* p, size_t n) {
	void (*my_malloc_handler) ();
	void* result;

	for(;;) {		// keep trying free and realloc
		my_malloc_handler = __malloc_alloc_oom_handler;
		if(0 == my_malloc_handler) { __THROW_BAD_ALLOC; }
		(*my_malloc_handler) ();		// call the handler again
		result = realloc(p, n);
		if(result) return result;
	}
}

// --------------------------------------------
typedef __malloc_alloc_template<0> malloc_alloc;

// convert the bytes to units
/*
 * usage:
 * template <class T, class Alloc = alloc>
 * class vector {
 *     typedef simple_alloc<T, Alloc> data_allocator;
 *     result = data_allocator::allocate(); 
 *     data_allocator::deallocate(result);
 * }
 */
template<class T, class Alloc>
class simple_alloc {
public:
	static T* allocate(size_t n) {		// n objects at a time
		return 0 == n ? 0 : static_cast<T*>(Alloc::allocate(n * sizeof(T)));
	}

	static T* allocate(void) {			// one object at a time
		return static_cast<T*>(Alloc::allocate(sizeof(T)));
	}

	static void deallocate(T* p, size_t n) { // free n objects
		if(0 != n) Alloc::deallocate(p, n * sizeof(T));
	}

	static void deallocate(T* p) { // free one object
		Alloc::deallocate(p, sizeof(T));
	}
};

static const int __ALIGN = 8;		// roundup border for small blocks
static const int __MAX_BYTES = 128;	// max size of small blocks 
static const int __NFREELISTS = __MAX_BYTES/__ALIGN;	// number of free-list

// level2 allocator(all static)
template<bool threads, int inst>
class __default_alloc_template {
private:
	static size_t ROUND_UP(size_t bytes) {
		return (((bytes) + __ALIGN - 1) & (__ALIGN - 1));
	}

private:
	union obj {
		union obj* free_list_link;
	};		// struct is OK

private:
	static obj* volatile free_list[__NFREELISTS];
	static size_t FREELIST_INDEX(size_t bytes) {	// get index accroding to size
		return (((bytes) + __ALIGN - 1) / __ALIGN - 1);
	}

	// returns an object of size n, and optionally adds to size n free list
	static void *refill(size_t n);

	// Allocate a chunk for nobjs of size "size". nobjs may be reduced
	// if it is inconvinient to allocate the requested number.
	static char* chunk_alloc(size_t size, int& nobjs);

	// Chunk allocation state
	static char* start_free;	// 'pool' head
	static char* end_free;		// 'pool' tail
	static size_t heap_size;	// sum of allocated memory

public:
	static void* allocate(size_t n) {	// n must be > 0
		obj** volatile my_free_list;
		obj* result;

		if(n > (size_t)__MAX_BYTES) {	// give it to the level one
			return(malloc_alloc::allocate(n));
		}
		 
		my_free_list = free_list + FREELIST_INDEX(n);
		result = *my_free_list;

		if(result == 0) {							// free_list empty
			void* r = refill(ROUND_UP(n));
			return r;
		}

		*my_free_list = result->free_list_link;		// reduce by one
		return result;
	}

	// never give back to the OS
	// BOGUS: advantage/disadvantages?
	static void deallocate(void* p, size_t n) {		// p is not 0
		obj* q = (obj*)p;
		obj** volatile my_free_list;	// obj**
										//
		if(n > (size_t)__MAX_BYTES) {
			malloc_alloc::deallocate(p, n);
			return;
		}

		my_free_list = free_list + FREELIST_INDEX(n);
		q->free_list_link = *my_free_list;
		*my_free_list = q;
	}

	static void* reallocate(void* p, size_t old_sz, size_t new_sz);

};

// We allocate memory in large chunks in order to avoid fragmenting
// the malloc heap too much. We assume that size is properly aligned/
// We hold the allocation lock.
template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::chunk_alloc(size_t size, int& nobjs) {
	char* result;
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free;

	if(bytes_left >= total_bytes) {
		result = start_free;
		start_free += total_bytes;
		return result;
	} else if(bytes_left >= size) {
		nobjs = bytes_left / size;
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return result;
	} else {
		size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
		// put pool to the suitable FREELIST
		if(bytes_left > 0) {
			obj** volatile my_free_list = free_list + FREELIST_INDEX(bytes_left);
			((obj*)start_free)->free_list_link = *my_free_list;
			*my_free_list = (obj*)start_free;
		}

		start_free = (char*)malloc(bytes_to_get);
		if(start_free == 0) {
			int i;
			obj* volatile *my_free_list, *p;
			// get memory from bigger blocks
			for(i = size; i <= __MAX_BYTES; i += __ALIGN) {
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;
				if(0 != p) {
					*my_free_list = p->free_list_link;
					start_free = (char*)p;
					end_free = start_free + i;		// treat this block as the memory pool
					return (chunk_alloc(size, nobjs));
				}
			}
		}
		heap_size += bytes_to_get;			// update memory pool
		end_free = start_free + bytes_to_get;
		return chunk_alloc(size, nobjs);
	}
}

// Returns an object of size n, and optionally adds to size n
// We assume that n is properly aligned. We hold the allocation lock.
template<bool threads, int inst>
void* __default_alloc_template<threads, inst>::refill(size_t n) {
	int nobjs = 20;
	char* chunk = chunk_alloc(n, nobjs);	// nobjs was passed by reference
	obj** volatile	my_free_list;
	obj* result;
	obj* current_obj;
	obj* next_obj;
	int i;
	if(1 == nobjs) return chunk;
	// hang the chunk on to the FREELIST
	my_free_list = free_list + FREELIST_INDEX(n);
	result = static_cast<obj*>(chunk);
	*my_free_list = next_obj = static_cast<obj*>(chunk + n);
	for(i = 1; ; ++i) {
		current_obj = next_obj;
		next_obj = static_cast<obj*>(static_cast<char*>(next_obj + n));
		if(nobjs - 1 == i) {		// last one
			current_obj->free_list_link = 0;
			break;
		} else {
			current_obj->free_list_link = next_obj;
		}
	}
	return result;
}

















