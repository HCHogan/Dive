#include <stddef.h>

typedef __int128 int128_t;

void store_prod(int128_t* dest, long long x, long long y) {
	*dest = x * (int128_t)y;
}

int main() {
	float a = 1000;
	double b = (double)a;
	return 0;
}
