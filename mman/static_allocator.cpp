#include <stddef.h>
#include <malloc.h>

namespace Ave {
	class allocator {
	private:
		struct obj{
			struct obj* next;		// embedded pointer
		};
	
	public:
		void* allocate(size_t size) {
			obj* p;
			if(!freeStore) {
				// linked list empty, acquire a new block of memory from the operating system
				size_t chunk = CHUNK * size;
				freeStore = p = (obj*)malloc(chunk);
	
				// generate the linked list
				for(int i = 0; i <= (CHUNK - 1); ++i) {
					p->next = (obj*)((char*)p + sizeof(size_t));
					p = p->next;
				}
				p->next = nullptr;		// last
			}
			p = freeStore;
			freeStore = freeStore->next;
			return p;
		}
	
		void deallocate(void* p, size_t) {
			// put p back into the front of the freelist
			((obj*)p)->next = freeStore;
			freeStore = (obj*)p;
		}
	
	private:
		obj* freeStore = nullptr;
		const int CHUNK = 5;		// just for testing
	};
}
