#include <stdio.h>
#include <string.h>

int main() {
	char buf[16];
	gets(buf);
	printf("%s", buf);
	return 0;
}
