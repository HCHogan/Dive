#include <vector>
#include "Tuple.hpp"
#include <iostream>

int main() {
	
	tuple<int, float, double, int*> mutup;
	std::cout << mutup[2];
	return 0;
}
