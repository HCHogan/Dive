#include <stdio.h>
#include <string.h>

char str[100];

int main() {
	scanf("%s", str);
	printf("len: %d\n", (int)strlen(str));
	for(int i = 0; str[i]; ++i) {
		printf("%c ", str[i]);
	}
	puts("");

	for(int i = strlen(str) - 1; i >= 0; --i) {
		printf("%c ", str[i]);
	}
}
