#include <stdlib.h>
#include <stdio.h>
int* pa = NULL;
int psize = 0;

void append(int x) {
	psize++;
	pa = realloc(pa,psize);
	// *(pa+psize-1) = x;
}

int main() {
	pa = malloc(sizeof(int));
	psize++;
	pa = 0;

	for(int i = 1; i <= 100; i++) {
		append(i);
	}

	return 0;
}
