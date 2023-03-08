#include <stdio.h>
#include <math.h>


float float_mov(double v1, double* src, double* dst) {
	double v2 = *src;
	*dst = v1;
	return v2;
}

double a, b;

int main() {
	a = 0.123456789;
	b = 0.987654321;
	float_mov(a, &a, &b);
	double c = pow(a, 0.5);
	return 0;
}
