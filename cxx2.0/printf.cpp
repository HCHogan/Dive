#include <iostream>
#include <stdexcept>

namespace Ave {
	void printf(const char* s) {
		while(*s) {
			if(*s == '%' && *(++s) != '%')
				throw std::runtime_error("invalid format string: missing args");
			std::cout << *s++;
		}
	}
	
	template<typename T, typename... Args>
	void printf(const char* s, T value, Args... args) {
		while(*s) {
			if(*s == '%' && *(++s) != '%') {
				std::cout << value;
				printf(++s, args...);	// call even when *s == 0 to detect extra arguments.
				return;
			}
			std::cout << *s++;
		}
		throw std::logic_error("extra arguments provided");
	}
}

int main() {
	Ave::printf("%d%d%d", 6,7.0,NULL);
	return 0;
}
