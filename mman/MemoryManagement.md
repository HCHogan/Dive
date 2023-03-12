# Libc Memory Management
## C++ primitives
1. malloc()		free()
2. new			delete 
3. ::operator new()		::operator delete()		可重载
4. allocator<T>::allocate()

### operator new
```cpp
void *operator new(size_t size, const std::nothrow_t&) _THROW0() {
	void* p;
	while ((p = malloc(size)) == 0) {
	_TRY_BEGIN
		if(_callnewh(size) == 0) break;		//call new handler when failed
	_CATCH(std::bad_alloc) return 0;
	_CATCH_END
	}
	return (p);
}
```
### array new
new[] 是从上向下ctor
delete[] 在gnuc中是从下往上反过来析

### replacement new 
c++中不能直接调用对象的构造参数(虽然在msvc中可以)
int* rp = new(&a)int(6);
replacement new 可以被重载,但是第一个参数必须是size_t
在class中重载比较常见

void* operator new(size_t size, int a) {
	return malloc(size);
	// ... 
}
调用时 new(&a, a)int(...)

### replacement delete
仅在new失败时调用
且每个重载版本的operator new 都有对应的 operator delete, 按照参数列表一一对应
例子:标准库basic_string用重载了operator new 带了一个size_t extra 用来实现reference counting
```cpp
template<...>
class basic_string {
private:
	struct Rep{...};
	...
	void release() { if(--ref == 0) delete this;}
	inline static void* operator new(size_t, size_t);
	inline static void operator delete(void*);
	inline static Rep* create(size_t);
	...
};

template<class charT, class traits, class Allocator>
inline basic_string<charT, traits, Allocator>::Rep*
basic_string<charT, traits, ALlocator>::Rep::create(size_t extra) {
	extra = frob_size(extra + 1);
	Rep* p = new(extra)Rep;
	...
	return p;
}
```

1. reduce cookie
2. faster

### new handler
当operator new 没有能力为你分配出你所申请的 memory 时,会抛出std::bad_alloc exception. 某些老旧的编译器会返回0,但你仍然可以上编译器这么做:
```cpp
new (nothrow) Foo;
```
这样为nothrow形式

抛出exception之前会不止一次的调用一个可有client指定的handler, 以下是new handler的形式和设定方法
```cpp
typedef void (*new_handler)();
new_handler set_new_handler(new_handler p) throw();
```
msvc operator new实现:
```cpp
void *operator new(size_t size, const std::nothrow_t&) _THROW0() {
	void* p;
	while ((p = malloc(size)) == 0) {
	_TRY_BEGIN
		if(_callnewh(size) == 0) break;		//call new handler when failed
											// if newh returns 0, break
	_CATCH(std::bad_alloc) return 0;
	_CATCH_END
	}
	return (p);
}
```
设计良好的new handler只有两个选择:
+ 让更多的memory可用
+ 调用abort或者exit()

```cpp
new_handler __cdecl set_new_handler (new_handler new_p) {
	// cannot use stub to register a new handler
	assert(new_p == 0);
	// remove current handler
	_set_new_handler(0);
	return 0;
}
```

## std::allocator
G2.9 BC5 VC6 的allocator也都只是operator new的套壳
there is a free_list[16] of freelist of various sizes.
aligned by 8 bytes.
there's a list of free space under each entry, the first block was passed to user, the list was managed by union obj(linked list)

**the number of the blocks is always between 1 to 20** 

1. 以三号为例,每次申请20x2x32+roundup(0>>4)个字节,前面20个做成freelist,后面20个留着备用, work as a memory pool
2. apply 64 bytes, as the pool is limited, the pool was divided into 640/64 = 10 blocks.
3. acquire 96 bits, as the pool is empty, we malloc 96*20*2+RoundUp(1280>>4), 19 of them was sent to list#11, the one left was passed to the user, and rest of the memory(2000 bytes) was prepared as a memory pool. Now, the total number of acquizition was 5200, the size of the pool is 2000.

Acquire for 72 bits, the system memory is not enough:
1. refill the pool with the nearest list(list#9, 80 bytes)
2. split the 80 bytes block into 72 and 8, pass the 72 bytes one to the user, and make the 8 bytes block left work as a pool.









