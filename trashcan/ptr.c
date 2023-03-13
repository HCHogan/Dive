#include <stdio.h>

char* p = NULL;
int* q = NULL;

int main() {
	printf("%p %p\n", p, q);
	++p, ++q;
	printf("%p %p\n", p, q);
}
