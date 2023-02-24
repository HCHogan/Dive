#include <pthread.h>
#include <stdio.h>

pthread_t chpth;
pthread_t fapth;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done = 0;
pthread_cond_t sig = PTHREAD_COND_INITIALIZER;

void* thr_exit() {
	pthread_mutex_lock(&lock);
	done = 1;
	pthread_cond_signal(&sig);
	pthread_mutex_unlock(&lock);
	return NULL;
}

void* child() {
	printf("hehehehe\n");
	thr_exit();
	return NULL;
}

void thr_join() {
	pthread_mutex_lock(&lock);
	while(done == 0) {
		pthread_cond_wait(&sig, &lock);
	}
	pthread_mutex_unlock(&lock);
}

int main() {
	printf("parent:begin\n");
	pthread_t p;
	pthread_create(&chpth, NULL, child, NULL);
	thr_join();
	printf("parent:end\n");
	return 0;
}
