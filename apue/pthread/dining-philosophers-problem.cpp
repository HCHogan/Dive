#include <pthread.h>
#include <semaphore.h>

sem_t forks[5];

int left(int p) {
	return p;
}

int right(int p) {
	return (p + 1) % 5;
}


