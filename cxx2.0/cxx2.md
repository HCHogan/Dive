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
**defines a type equivalent to the type of an expression**
declval converts any type T to a reference type, making it possible to use member funcitons in decltype expressions without the need to go through constructors.

decltype allows the compiler to infer the return type of a function based on an arbitrary expression, which makes perferct **forwarding** more generic. In past versions, for two arbitrary types T1 and T2, there was no way to deduce the type of an expression that used these two types. The decltype feature allows you to state, for example, an expression that has template arguments, such as sum**<T1, T2>()** has the type **T1 + T2**

By using the new decltype keyword, you can let the compiler find out the type of an expression. This is the realization of the often requested **typeof** feature. However, the existing typeof implementations were inconsistent and incomplete, so C++11 introduced a new keyword. For example:
```cpp
map<string, float> coll;
decltype(coll)::value_type elem;
// before C++11 map<string, float>::Value_type elem;
```
One application of decltype is to declare return types. Another is to use it in **metaprogramming** or to pass the type if a lambda.

#### decltype, used to declare return types
sometimes, the return type of a function depends on an expression processed with arguments.
However, something like
```cpp
tempalte<typename T1, Typename T2>
decltype(x+y) add(T1 x, T2, y);
```
was not possible before C++11, because the return expression uses objects not introduced or in scope yet.
But with C++11, you can alternatively declare the return type of a funciton behind the parameter list:
```cpp
auto add(T1 x, T2 y) -> decltype(x+y);
```
This uses the same syntax as for lambdas to declare return types.

#### decltype, used for metaprogramming
```cpp
template<typename T> 
void test18_decltype(T obj) {
	map<string, float>::value_type elem1;			// 面对type,可以取其inner typedef

	map<string, float> coll;
	decltype(coll):value_type elem2;				// 面对obj,取其class type 的 inner typedef
}
test19_decltype(complex<int>)());					// 编译失败
```

#### decltype, used to pass the type of a lambda
```cpp
auto cmp = [](const Person& p1, const Person& p2) {
	return p1.lastname() < p2.lastname()
};
...
std::set<Person, decltype(cmp)> coll(cmp);
```
面对lambda,我们手上往往只有object,没有Type,要获得type只能用decltype
()是什么意思? function call

### Lambdas
auto l = [](int x) -> bool { };
C++11 introduced *lambdas*, allowing the definition of inline functionality, which can be used as a parameter or a local object. Lambdas change the way the C++ standard library is used.
A lambda is a **definition of functionality** that can be defined inside statements and expressions. Thus, you can use a lambda as an inline funciton. The minimal lambda function has no parameters and simply does something:
```cpp
[] {
	std::cout << "hello lambda" << std::endl;
}
```
you can use it directly:
```cpp
[] {
	std::cout << "hello lambda" << std::endl;
} ();			// prints hello lambda
```
or pass it to the objects to get called:
```cpp
auto I = [] {
	std::cout << "hello lambda" << std::endl;
}
...
I();			// prints hello lambda
```

**[...] (...) mutableopt throwSpecopt ->returnTypeopt {...};**
[ : lambda introducer
... : **capture** to access **nonstatic outside objects** inside the lambda. Static objects such as std::cout can be used. you can specify a capture to access data of outer scope that is not passed as an argument:
[=] means that the outer scope is passed to the lambda by value.
[&] means that the outer scope is passed to the lambda by reference.
mutable: objects that are passed by value, but inside the funciton object defined by the lambda, you have write access to the passed value.
returnType: without any specify definition, it is deduced from the return value.
Ex:
```cpp
int x = 0;
int y = 42;
auto qqq = [x, &y] {...};		// pass x by value, y by reference
								// [=, &y] to pass y by reference and all other objects by value.
```
In fact, the type of a lambda is an anonymous function object(or functor) which overloaded the **function call** operator.(())
```cpp
int id = 0;
auto f = [id]() mutable {
	std::cout << "id:" << id << std::endl;
	++id; //OK
};

id = 42
f(); f(); f();					// prints 0, 1, 2
std::cout << id << std::endl;	// prints 42
```
This equals to:
```cpp
class Functor {
private:
	int id;						// copy of outside id
public:
	void operator() () {
		std::cout << "id" << id << std::endl;
		++id;					// OK
	}
};
Functor f;
// but without mutable, you do not have the power to give yourself the permission to have access to writing the id object.
```
if passed by reference
```cpp
auto f = [&id](int param) {
	cout << "id:" << id << endl;
	++id; ++param;				// OK
};
id = 42;
f(7);
f(7);							//43
f(7);							//44
std::cout << id << std::endl;	//45

int id = 0;
auto f = [id]() {
	cout << "id" << endl;
	++id;						// G, increment of read-only variable 'id'
};
```
mutable 表示仿函数这个类中的这个捕获的值可不可以被改变
个人理解就是const int id = 1;
Because you need the type of the lambda for the declaration of the set, decltype must be used, which yields the type of a lambda object, such as cmp. Note that you also have to pass the lambda object to the constructor of coll; otherwise, coll would call the default constructor for the sorting criterion passed, and by rule lambdas have no default constructor and no assignment operator. So, for a sorting criterion, a class defining the function objects might still be more intuitive.
**因此如果被调用,编译器报错use of undeclared function ...**

### Variadic Templates
+ 谈的是Templates
- function Templates
- class Templates
+ 变化的是templates parameters
- variable number  利用参数个数逐一递减的特性,实现递归函数的调用
- different type	利用参数个数逐个递减导致参数类型也逐一递减的特性,实现递归继承或复合,以class template 完成
for example:
```cpp
template<typename T, typename... Types>
void func(const T& firstArg, const Types&... args) {
	// 处理firstArg
	func(args...)
}
```
```cpp
template<typename args...> 和 template<typename T, typename... args> 可以共存,前者更加泛化,应为后者只能穿两个或以上的参数

```
EG:
+ printf.cpp
+ max.cpp
## libraries (header files)

