#include <pthread.h>
#include <stdio.h>

void* myfunc(void* a) {
	int n = (int)a;
	printf("ok, a = %d\n", n);
	return (void*)a;
}
int main() {
	pthread_t p;
	int rc = 0;
	int rcc;
	pthread_create(&p, NULL, myfunc, &rc);
	pthread_join(p, (void**)rcc);
	printf("ok, rcc = %d\n", rcc);
	return 0;
}
