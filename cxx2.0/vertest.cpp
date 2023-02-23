#include <iostream>
using namespace std;
int main() {
	std::cout << __cplusplus << std::endl;
	return 0;
}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
	cout << firstArg << endl;
	print(args...);
}
	