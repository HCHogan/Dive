#include <stddef.h>
#include <memory>
#include <new>

template<class T>
class allocator {
public:
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;
	typedef T*			pointer ;
	typedef T			value_type ;

	pointer allocate(size_t n, allocator<void>::const_pointer = 0) {
		pointer tmp = static_cast<pointer>(::operator new(n * sizeof(value_type)));
		return tmp;
	}
	
	void deallocate(pointer p, size_type) {
		::operator delete(p);
	}
	// ....
};
