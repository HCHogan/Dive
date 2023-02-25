#include <semaphore.h>
#include <stdint.h>

typedef struct _rwlock_t {
	sem_t lock;
	sem_t writelock;
	int readers;
} rw_lock_t;

void rm_lock_init(rw_lock_t* rw) {
	rw->readers = 0;
	sem_init(&rw->lock, 0, 1);
	sem_init(&rw->writelock, 0, 1);
}

void rwlock_acquire_readerlock(rw_lock_t* rw) {
	sem_wait(&rw->lock);
	rw->readers++;
	if(rw->readers == 1) {
		sem_wait(&rw->writelock);		// first reader acquires the writelock
	}
	sem_post(&rw->lock);
}
