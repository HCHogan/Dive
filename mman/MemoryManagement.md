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
## 自己实现一个类的小型内存管理
1. reduce cookie
2. faster






