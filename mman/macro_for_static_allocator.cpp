// DECLARE_POOL
#define DECLARE_POOL_ALLOC() \
public: \
	void* operator new(size_t size) { return myAlloc.allocate; } \
	void operator delete(void* p) { myAlloc.deallocate(p, 0); } \
protected: \
	static allocator myAlloc;

// IMPLEMENT_POOL_ALLOC -- used in class implementation
#define IMPLEMENT_POOL_ALLOC(class_name) \
allocator class_name::myAlloc;


//usage:
/*
class Foo {
	DECLARE_POOL_ALLOC();
public:
	long l;
	string str;
public:
	Foo(long l): l(l) { }
};
IMPLEMENT_POOL_ALLOC(Foo)
*/	
