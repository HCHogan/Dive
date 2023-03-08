#include <stdio.h>

double a, b;

int main() {
	a = 0.123456789;
	b = 0.987654321;
	if(a > b) printf("OK>\n");
	else if(a < b) printf("OK<\n");
	else if(a == b) printf("OK=\n");
	else printf("Not OK\n");

	return 0;
}
