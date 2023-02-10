## STL体系结构基础介绍
### STL六大部件(Compononts)：
> 容器(Containers)  
> 分配器(Allocators)  
> 算法(A1gorithms)  
> 迭代器(Iterators)  
> 适配器(Adapters)  
> 仿函数(Functors) 作用像函数对象的操作  
泛型编程 容器与算法分开  
容器由分配器分配 迭代器类似于泛型指针  
Container/Iterator/Functor Adapters:可以对容器，迭代器等做转换

```cpp
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int main()
{
    int ia[6]={27,210,12,47,109,83};
    vector<int,allocator<int>> vi(ia,ia+6);
    cout << count_if(vi.begin(),vi.end(),notl(bind2nd(less<int>(),40))); //计算出范围内符合这个条件的东西有几个

    return 0;
}
```

STL容器的迭代器均为前闭后开区间

### range-based for statement(since C++11)
推荐这样写
```cpp
for(decl:coll)
{
    statement;
}
for(int i:{2,3,4,5,6})      //遍历
{
    std::cout<<i<<std::endl;
}
std::vector<double> vec;
...
for(auto elem : vec)
{
    std::cout<<elem<<std::endl;
}
for(auto& elem : vec)
{
    elem*=3;
}
```
### auto keyword(适度使用)
```cpp
list<string> c;
...
list<string>::iterator ite;
ite=::find(c.begin(),c.end(),target);
//可以转化成下面这种
list<string> c;
...
auto ite=::find(c.begin(),c.end().target)
```
## 容器-结构与分类
> Sequence Containers: Array,Vecetor,Deque,List,ForwardList  
> Associative Containers: Set/Multiset, Map/Multimap  
> Unordered Containers: Unordered Set/Multiset, Unordred Map/Multimap  

C++标准库用的是HashTable with Seperate Chaining 目前最好

## vector
三根指针，start,finish,end_of_storage
二倍扩张，没什么好讲的

## deque深度探索
deque是双端队列，通过动态连续的缓冲区来实现
对外号称连续（显现出来的特性），实际不然。
模拟线性归功于复杂的iterator

deque类有4个东西
iterator start
iterator finish
map_pointer map         指向中控中心的指针
size_type map_size      中控中心的大小

中控中心是使用vector实现的一块连续内存，每个元素是一个T*,所以map_pointer是T**
每次中控中心长度不够需要扩张时，申请一个2倍大的vector，然后把元素放在新vector的中间，实现双向扩张

deque效率不及vector，因此能用vector尽量使用vector
### 3个参数
T
allocator
buff_size       缓冲区大小，默认512字节，如果一个T超过512字节，那就是sizeof T
### iterator结构
T* cur              指向当前缓冲区现在那个元素
T* first            指向当前缓冲区的第一个元素
T* last             指向当前缓冲区的最后一个元素
map_pointer node    指向map中指向这个缓冲区的指针


## rbtree
查找非常快、插入也非常快
red-tree红黑树是平衡二元搜索树中常用的一种。
平衡二元搜索树的特性：排列规则有利search和insert，并保持适度平衡——无任何结点过深。

rb_tree提供“遍历”操作及iterators.
按正常规则（++it）遍历，便能够获得排序状态（sorted）。

不能使用rb-tree的iterator改变元素值（因为其元素具有严谨的排列规则）。编程里面并未阻绝此事。如此设计是正确的，因为rb_tree即将为set和map服务（作为其底部支持），map有key和data两部分，而map允许元素的data被更改，只有元素的key才是不可以被更改的。

红黑树提供两种insertion操作：inert_unique()和insert_equal()。前者便是结点的key一定在整个tree中独一无二，否则安插失败，但是程序不会奔溃也不会报错就是安插不进去。后者表示结点的key可以被重复，被安插在被重复的附近。

Compare可以看成一个函数 实际上是一个类
红黑树只以三笔资料表现自己

size_tyoe 4字节
link_type 4字节
Compare 1字节
但是要4的倍数对齐 所以最后是12字节
### 5个参数
key             //就是key
value
KeyOfValue      //仿函数，怎么从value中提取出key
compare         //仿函数，怎么比较key
allocator       //分配器

## set,multiset深度探索
set,multiset都是基于rbtree实现的
set和multiset 中，rbtree的key=value
所以keyofvalue用的是identity<int>
内部定义了一个红黑树t

不提供可以改变元素值的iterator,底层上通过使用const iterator来实现

## map,multimap深度探索
map,multimap都是基于rbtree实现的
map的value是pair<const key, realvalue>，这样key不可以改变，而value能改变
内部定义了一个红黑树t

## hashtable深度搜索
如果元素数量比篮子多，就要rehashing（没有科学数据，纯经验）
### 6个参数
Value
Key
HashFcn
ExtractKey      //怎么拿出key
EqualKey        //什么叫做key相等
Alloc           //分配器
### iterator
```cpp
node* cur           //指向元素本身
hashtable* ht       //指向hashtable
```
### 包含5个内容
//typedef __hashtable_node<value> node;
hasher hash;
key_equal;
ExtractKey get_key;
vector<node*,Alloc> buckets;
size_type num_elements;
4+12+1+1+1=19  对齐->  20
sizeof()=20
```cpp
//node的结构
template <class Value>
struct __hashtable_node
{
    __hashtable_node* next;
    Value val;
}       //相当于单链表(GNU C)//vc是双链表方便--
```

## 算法
C++ STL算法
算法Algorithm是个function template
仿函数Functor是个class template
Algorithms看不见containers，对其一无所知；
所以他所需要的一切都必须由iterators取得；
而iterators必须能够回答Algorithms的所有提问，才能搭配该algorithm的所有操作

## 迭代器的分类(category)
**5种iterator category**
```cpp
struct input_iterator_tag { }; struct output_iterator_tag { };

struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };
```
特别的，display(istream_iterator<int>())=input_iterator_tag;
display(ostream_iterator<int>(cout,""))=output_iterator_tag;
利用#include <typeinfo>可以打印出typeid
cout<<typeid(itr).name()<<endl;

## typename 类型名指示符
考虑下面的错误代码
```cpp
template <class T>
void foo(const T& t)
{
    // 声明一个指向某个类型为T::bar的对象的指针
    T::bar * p;
}
 
struct StructWithBarAsType
{
    typedef int bar;
}; 
 
int main()
{
    StructWithBarAsType x;
    foo(x);
}
```
这段代码看起来能通过编译，但是事实上这段代码并不正确。因为编译器并不知道T::bar究竟是一个类型的名字还是一个某个变量的名字。究其根本，造成这种歧义的原因在于，编译器不明白T::bar到底是不是“模板参数的非独立名字”，简称“非独立名字”。注意，任何含有名为“bar”的项的类T，都可以被当作模板参数传入foo()函数，包括typedef类型、枚举类型或者变量等。
为了消除歧义，C++语言标准规定：
A name used in a template declaration or definition and that is dependent on a template-parameter is assumed not to name a type unless the applicable name lookup finds a type name or the name is qualified by the keyword typename.
意即出现上述歧义时，编译器将自动默认bar为一个变量名，而不是类型名。所以上面例子中的代码 T::bar * p 会被解释为乘法，而不是声明p为指向T::bar类型的对象的指针。
如果还有另一个名为StructWithBarAsValue类型，如下：
```cpp
struct StructWithBarAsValue
{
    int bar;
};
```
那么，编译器将以完全不同的方式来解释 T::bar * p 的含义。
解决问题的最终办法，就是显式地告诉编译器，T::bar是一个类型名。这就必须用typename关键字，例如：
```cpp
template <typename T>
void foo(const T& t)
{   
    // 声明一个指向某个类型为T::bar的对象的指针
    typename T::bar * p;
}
```
这样，编译器就确定了T::bar是一个类型名，p也就自然地被解释为指向T::bar类型的对象的指针了。
### iterator_tags

### example
cout << count_if

## std::bind
可以绑定：
1. functions
2. function objects, _1 必须是某个object地址
3. member functions, _1 必须是某个object地址
4. data members
```cpp
double my_divide(double x, double y) {
	return x/y;
}

struct my_pair {
	double a,b;
	double multiply() {return a * b}
};

using namespace ::std::placeholders;

auto fn_five = bind(my_divide, 10, 2);
cout << fn_five() << '\n';

auto fn_half = bind(my_divide, _1, 2);		//have a placeholder here
cout << fn_half(10);

auto fn_invert = bind(my_divide, _2, _1);
cout << fn_invert(10, 2);

auto fn_rounding = bind<int>(my_divide, _1, _2);
cout << fn_rounding(10, 3) << '\n';				// cout 3

// binding members
my_pair ten_two {10, 2};	// member function 其实有个argument: this
							// c++ 11 才有这个写法

auto bound_memfn = bind(&my_pair::multiply, _1);	// returns x.multiply()
cout << bound_memfn(ten_two) << endl;				//相当于调用了ten_two.multiply

auto bound_memdata = bind(&my_pair::a, ten_two);	// return ten_two.a
cout << bound_memdata() << endl;					// 10

auto bound_memdata2 = bind(&my_pair::b, _1);		// return x.b
cout << bound_memdata2(ten_two) << endl;

int n = count_if(v.cbegin(), v.cend(), not1(bind2nd(less<int>(), 50)));
auto fn_ = bind(less<int>(), _1, 50);
int n = count_if(v.cbegin(), v.cend(), fn_) << endl;
```

## Object-Oriented Programming
+ In obeject-oriented concepts, inheriting a class as public means that they have an "is" relationship.

