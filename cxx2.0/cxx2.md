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

### lambda
auto l = [](int x) -> bool { };

### move Semantics


### auto


## libraries (header files)

