#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <string_view>

std::basic_string<int> si;

template<typename T>
using mystring = ::std::basic_string<T, ::std::char_traits<T>, ::std::allocator<T>>;

int main() {
	si = {1, 2, 3};
	auto it = si.begin();
	::std::iterator_traits<mystring<int>::iterator>::value_type a = 1;

}

