#include <stdio.h>
#include <signal.h>

void handler(int arg) {
	printf("signal received!\n'");
	return;
}

int main() {
	signal(SIGHUP, handler);
	while(1);
	return 0;
}
