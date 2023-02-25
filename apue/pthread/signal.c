#include <semaphore.h>
sem_t s;

int main(int argc, char* argv[]) {
	sem_init(&s, 0, 1);
}
