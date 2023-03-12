#include <stddef.h>

// DO NOT USE THIS FILE unless you have an old container implementation requires an allocator with the HP-style interface.
// This file is not included in any other SGI STL
template<class T>
class allocator {
public:
	typedef T			value_type;
	typedef T*			pointer;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;

	pointer allocate(size_type n) {
		return ::allocate((difference_type)n, (pointer)0);
	}

	void deallocate(pointer p) {
		::deallocate(p);
	}
};
