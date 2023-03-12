#include <stddef.h>

template<class T>
class allocator {
public:
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T value_type;
	
	pointer allocate(size_type _N, const void*) {
		return (_Allocate((difference_type)_N, (pointer)0));
	}
	void deallocate(void* _P, size_type) {
		operator delete(_P);
	}
};

template<class T> inline
T* _Allocate(ptrdiff_t _N, T*) {
	if(_N < 0) _N = 0;
	return ((T*)operator new((size_t)_N * sizeof(T)));
}
