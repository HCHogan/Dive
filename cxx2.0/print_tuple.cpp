#include <iostream>
#include <ostream>
#include "./Tuple.hpp"

namespace Ave {
	using std::ostream;
	
	// print element with IDX of tuple
	template<int IDX, int MAX, typename... Args>
	struct PRINT_TUPLE {
		static void print(ostream& os, const tuple<Args...>& t) {
			os << get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
			PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
		}
	};

	template<int MAX, typename... Args>
	struct PRINT_TUPLE<MAX, MAX, Args...> {
		static void print(std::ostream& os, const tuple<Args...>& t) {

		}
	};
	
	template<typename... Args>
	std::ostream& operator<<(std::ostream& os, const tuple<Args...>& t) {
		os << "[";
		PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
		return os << "]";
	}
}
