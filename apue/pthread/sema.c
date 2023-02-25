#include <semaphore.h>
#include <stdio.h>

sem_t full, empty;
sem_t mutex;
int buffer[100];
int fill, use;
const int MAX = 100;

void put(int x) {
	buffer[fill] = x;
	fill = (fill + 1) % MAX;
}

int get() {
	int temp = buffer[use];
	use = (use + 1) % MAX;
	return temp;
}

void* producer(void* arg) {
	int i;
	for(i = 0; i < 100; i++) {
		sem_wait(&empty);
		sem_wait(&mutex);
		put(i);
		sem_post(&mutex);
		sem_post(&full);
	}
	return NULL;
}

void* consumer(void* arg) {
	int tmp;
	sem_wait(&full);
	sem_wait(&mutex);
	tmp = get();
	sem_post(&mutex);
	sem_post(&empty);

	return NULL;
}

// this is good.
//
int main() {
	sem_init(&mutex, 0, MAX);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, 1);
	return 0;
}
