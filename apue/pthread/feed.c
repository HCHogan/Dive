#include <assert.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>

int buffer;
int count = 0;

pthread_cond_t cond;
pthread_mutex_t lock;
pthread_t pth1;

const int loops = 100;

void put(int value) {
	assert(count == 0);
	count = 1;
	buffer = value;
}

int get() {
	assert(count == 0);
	count = 0;
	return buffer;
}

void* producer(void* arg) {
	int i;
	for(i = 0; i < loops; i++) {
		pthread_mutex_lock(&lock);
		while(count == 1) {
			pthread_cond_wait(&cond, &lock);
		}
		put(i);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

void* consumer(void* arg) {
	int i;
	for(i = 0; i < loops; i++) {
		pthread_mutex_lock(&lock);
		while(count == 0) pthread_cond_wait(&cond, &lock);
		int tmp = get();
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
		printf("%d", tmp);
	}
	return NULL;
}

