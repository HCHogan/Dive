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

### Uniform Initialization
+ Before C++11, programmers, especially novices, could easily become confused by the question of how to initialize a variable or an object. Initialization could happen with parentheses, braces, and/or assignment operators.
+ For this reason, C+ + 11 introduced the concept of uniform initialization, which means that for any initialization, you can use one common syntax. This syntax uses braces, so the following is possible now.
+ 其實是利用一個事實：編譯器看到 {11,2...1} 便做出一個 initializer list<T>,它關聯至一 個 array<T,n>可西數（例如ctor) 時該 array 内的元素可被編譯器分解逐一傳給西數。但若西數參數是個 initializer_list<T>，調用者卻不能給予數個T参數然後以為它們會被白動轉為一個 initializer_list<T>傳入
```cpp
int values[] {1, 2, 3};
vector<int> v {2, 3, 5, 7};
vector<string> cities { "Ber", "New York", "Lon"};
//  这会形成一个initializer_list<string>,背后有个array<string,6>,调用vector<string> ctors时编译器找到了一个接受initializer_list<string>的ctor. 所有容器都有此ctor.
complex<double> c {4.0, 3.0}; 
//形成一个initializer_list<double,2>, 而complex的ctor并无任何接受initializer_list的ctor,所以分解为一个个但个元素传给ctor.
```
### Range based for-loop
```cpp
for( decl : coll ) {
	statements;
}

for (int x : {1, 2, 3}) {

}
coll 只要是容器,iteratable就行

```
+ 当C的ctor定义的时候用了explicit 就不能const C& elem : val

explicit为清晰的;明确的之意.顾名思义,关键字explicit可以阻止隐式转换的发生.
例如: C++中只带有一个参数的构造函数,或者或者除了第一个参数外其余参数都有缺省值的多参构造函数,承担了两个角色:
1.用于构建单参数的类对象.
2.隐含的类型转换操作符.

例如:一个类A的构造函数A(int i)就是，既可以用来作为构造器，又可以实现隐式转换A a=1；因为1可以通过构造函数A(int i)转换为一个类A的对象。(隐含的类型转换操作符)
但有时我们并不想让他进行隐式类型转换,这时C++的explicit关键字就起到作用了.

### default & delete
如果你自行定義了一個 ctor，那麼編譯器
就不會再給你一個 default ctor。
如果你強制加上=deault，就可以重新獲得並使用 default ctor。
= delete 就是不用这个ctor

### Alias template
原来只能这样写,如果不标准,那寄
```cpp
template<typename Container>
void test_movable(Container ctnr) {
	typedef typename iterator_traits<typename Container::iterator>::value_type Valtype;

	for(long i = 0; i <= SIZE; i++) {
		ctnr.insert(c.end(), Valtype);
	}

	output_static_data(*(ctnr.begin()));
		
	Container c1(ctnr);
	Container c2(std::move(c));

	c1.swap(c2);
}
test_movable(list<std::string>());
```
使用alias Template
```cpp

```

### Template template parameter
```cpp
template<typename T, template<class> class Container>
class XCls {
private:
	Container<T> c;
}

XCls<MyString, vector> cl;
// ERROR: vector有两个模板参数 但是申明里面只写传了一个 报错
// 这个时候使用alias template
template<typename T>
using Vec = vector<T, allocator<T>>;	//绑定两个参数

XCls<Mystring, Vec> c1;
```

### noexcept
```cpp
void foo() noexcept(true);
void swap(Type& x, Type& y) noexcept(noexcept(x.swap(y))) {
	x.swap(y);
}
```
if the program throws, the program will terminate, calling std::terminate(), which by default calls std::abort()
Specifying noexcept without condition is a short form of specifying noexcept(true)

You need to inform C++ (specially std::vector) that your move constructor and destructor does not throw. Then the move constructor will be called when the vector grows. If the constructor is not noexcept, std::vecotr can't use it. Since the it can't ensure the exception guarantees demanded by the standard.
 that your move constructor and destructor does not throw. Then the move constructor will be called when the vector grows. If the constructor is not noexcept, std::vecotr can't use it. Since the it can't ensure the exception guarantees demanded by the standard.
由于vector无法处理这些异常，所以必须申明为noexcept vector才能放心调用move constructor.

```cpp
class MyString {
private:
	char* _data;
	size_t _len;
	...

public:
	// move constructor
	MyString(MyString&& str) noexcept
	: _data(str.data), _len(str.len) {...}

	// move assignment
	MyString& operator=(MyString&& str) noexcept
	{ ... return *this; }
}
```
#### stack unwinding
**栈展开(stack unwinding)的定义**

抛出异常时，将暂停当前函数的执行，开始查找匹配的 catch 子句。首先检查 throw 本身是否在 try 块内部，如果是，检查与该 try 相关的 catch 子句，看是否可以处理该异常。如果不能处理，就退出当前函数，并且释放当前函数的内存并销毁局部对象，继续到上层的调用函数中查找，直到找到一个可以处理该异常的 catch 。这个过程称为栈展开(stack unwinding)。当处理该异常的 catch 结束之后，紧接着该 catch 之后的点继续执行。为局部对象调用析构函数

在栈展开的过程中，会释放局部对象所占用的内存并运行类类型局部对象的析构函数。但需要注意的是，如果一个块通过 new 动态分配内存，并且在释放该资源之前发生异常，该块因异常而退出，那么在栈展开期间不会释放该资源，编译器不会删除该指针，这样就会造成内存泄露。

析构函数应该从不抛出异常

在为某个异常进行栈展开的时候，析构函数如果又抛出自己的未经处理的另一个异常，将会导致调用标准库 terminate 函数。通常 terminate 函数将调用 abort 函数，导致程序的非正常退出。所以析构函数应该从不抛出异常。

异常与构造函数

如果在构造函数对象时发生异常，此时该对象可能只是被部分构造，要保证能够适当的撤销这些已构造的成员。

未捕获的异常将会终止程序

不能不处理异常。如果找不到匹配的catch，程序就会调用库函数terminate。

### override
override means that the compiler will check the base class to see if there is a virtual function with this exact signature.
Base: virtual void vfunc(float);
Derive: virtual void vfunc(int);
在之前版本这样做子类会创建一个新的virtual function
CXX2.0中,使用virtual void vfunc(float) override 显式告诉编译器你要重写
如果写成了virtial void vfunc(int) override 则会报错

### final
struct Base1 final { };
告诉编译器这是继承链的最后一个,不能再被继承,否则报错
virtual void f() final;
告诉编译器不允许被它的子类复写,否则报错

### decltype
declval converts aany type T to a 

### lambda
auto l = [](int x) -> bool { };

### move Semantics


### auto


## libraries (header files)

