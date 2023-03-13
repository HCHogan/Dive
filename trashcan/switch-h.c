#include <stdio.h>

const int N = 66;

int main() {
	int i = 0;
	do {
		scanf("%d", &i);
		if(i > 66) printf("too big\n");
		else if(i < 66) printf("too small\n");
		else printf("correct\n");
	} while(i != 66);
	return 0;
}
