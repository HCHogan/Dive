#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int x = 0;

int main(int argc, char* argv[]) {
	x = 100;
	int rc = fork();
	if (rc < 0) {
		printf("G\n");
		exit(1);
	} else if (rc == 0) {
		close(STDOUT_FILENO);
		printf("hahaha\n");
	} else {
		printf("father: x = %d", x);
		printf(" pid = %d\n", (int)getpid());
	}
	return 0;
}
