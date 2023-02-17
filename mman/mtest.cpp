#include <cstddef>
#include <malloc/_malloc.h>
#include <memory>
#include <new>
#include <vector>
#include <iostream>
using namespace std;

vector<int> a;

int main() {
	cout << allocator<int>().max_size() << endl;
	return 0;
}

