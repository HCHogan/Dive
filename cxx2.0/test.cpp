#include <iostream>
using std::cout;
using std::endl;
int x = 1;
template<typename T1, typename T2>
auto myfunc(T1 x, T2 y) -> decltype(x + y) {
	return x + y;
}

int main() {
	cout << "hehe" << endl;
	cout << myfunc(1, 2.0) << endl;

	[=](int x)mutable ->int {
		return ++x;
	}(x);

	return 0;
}
