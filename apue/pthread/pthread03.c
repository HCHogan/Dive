#include <pthread.h>
#include <stdio.h>
#include <assert.h>

pthread_mutex_t lock;
int countc = 0;
int count = 0;
void* myfunc(void* arg) {
	for(int i = 1; i <= 100000; i++) {
		++countc;
		int rc = pthread_mutex_lock(&lock);
		assert(rc == 0);
		++count;
		pthread_mutex_unlock(&lock);
	}
	return (void*)0;
}

int main() {
	pthread_mutex_init(&lock, NULL);	

	pthread_t p1,p2;

	pthread_create(&p1, NULL, myfunc, 0);
	pthread_create(&p2, NULL, myfunc, 0);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	printf("ok, count = %d\n", count);
	printf("countc = %d\n", countc);

	return 0;
}
