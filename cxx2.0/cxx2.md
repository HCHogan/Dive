# C++ 2.0 New Features
C++ 98 (1.0)
c++ 03 (TR1)
c++ 11 (2.0)
c++ 14

## Language

### Variadic Templates
```cpp
void print() {

}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {	//可以是任何类型的任意数量的东西
	cout << firstArg << endl;	// print first argument
	print(args...);				// call print() for remaining arguments
}

// inside the vt, sizeof...(args) yields the number of arguments
```
... 就是所谓的pack(包)
可以很方便的完成recursive function call
EG: CustomerHash.hpp
EG: Tuple
### move Semantics

### auto


## libraries (header files)

