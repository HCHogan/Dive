#include <iostream>
#include <vector>
#include <tuple>

using std::cout;
using std::endl;

template<typename T1, typename T2>
auto myfunc(T1 x, T2 y) -> decltype(x + y) {
	return x + y;
}

std::vector<int> vi{5, 28, 50, 83, 70};
int x = 30;
int y = 100;

void printX() {

}

template<typename T, typename... Types>
void printX(const T& firstArg, const Types&... args) {
	cout << firstArg << endl;
	printX(args...);
}

int main() {
	cout << "hehe" << endl;
	cout << myfunc(1, 2.0) << endl;
	printX(7.5, "hello", &"hello", NULL);

//	vi.erase(remvoe_if(vi.begin(), vi.end(), [x,y](int n) { return x < n && n < y; }))

	[=](int x)mutable ->int {
		return ++x;
	}(x);

	int id = 42;
	auto f = [&id](int& param) {
		cout << "id:" << id << endl;
		++id; ++param;				// OK
	};
	int a = 7;
	f(a);
	f(a);							//43
	f(a);							//44
	std::cout << id << std::endl;	//45
	std::cout << a << std::endl;

	return 0;
}
