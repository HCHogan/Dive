#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>
namespace Ave {

class allocator {
private:
	struct obj {
		struct obj* next;
	};
public:
	void* allocate(size_t);
	void deallocate(void*, size_t);
private:
	obj* freeStore = nullptr;
	const int CHUNK = 5;			// 小一些以便观察
};

void* allocator::allocate(size_t size) {
	obj* p;
	if(!freeStore) {
		// linked list 为空,申请
		size_t chunk = CHUNK * size;
		freeStore = p = (obj*)malloc(chunk);

		for(int i = 0; i < (CHUNK - 1); i++) {
			p->next = (obj*)((char*)p + 1);
		}
		p->next = nullptr;
	}
	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

void allocator::deallocate(void* p, size_t) {
	((obj*)p)->next = freeStore;
	freeStore = (obj*)p;
}

};

// 使用时
class foo {
private:
	static Ave::allocator m_allocator;

};
