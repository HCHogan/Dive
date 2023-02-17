#include "./initializer_list.hpp"

template<typename _Tp>
inline _Tp min(initializer_list<_Tp> __l) {
	return *std::min_element(__l.begin(), __l.end());
}

template<typename _Tp>
inline _Tp max(initializer_list<_Tp> __l) {
	return *std::max_element(__l.begin(), __l.end());
}


