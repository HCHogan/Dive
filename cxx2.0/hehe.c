#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

pthread_t pth1;
pthread_t pth2;

pthread_mutex_t lock;

static int x = 0;

void* work(void* arg) {
	for(int i = 0; i < 100; ++i) {
		pthread_mutex_lock(&lock);
		++x;
		pthread_mutex_unlock(&lock);
		printf("%d ",x);
	}
	return NULL;
}

int main() {
	pthread_create(&pth1, NULL, work, NULL);
	pthread_create(&pth2, NULL, work, NULL);

	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);

	printf("\n%d\n",x);

	return 0;
}
