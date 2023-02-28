#include <semaphore.h>
#include <stdint.h>

typedef struct _rwlock_t {
	sem_t lock;					// binary semaphore
	sem_t writelock;			// used to allow ONE writer or MANY writers
	int readers;				// count of readers reading in critical section
} rw_lock_t;

void rm_lock_init(rw_lock_t* rw) {
	rw->readers = 0;
	sem_init(&rw->lock, 0, 1);
	sem_init(&rw->writelock, 0, 1);			//为0的时候只在本进程内共享, value是初始值
}

void rwlock_acquire_readlock(rw_lock_t* rw) {
	sem_wait(&rw->lock);
	rw->readers++;
	if(rw->readers == 1) {
		sem_wait(&rw->writelock);		// first reader acquires the writelock
	}
	sem_post(&rw->lock);
}

void rwlock_release_readlock(rw_lock_t* rw) {
	sem_wait(&rw->lock);
	rw->readers--;
	if(rw->readers == 0) {
		sem_post(&rw->writelock);		// last reader release the lock
	}
}

void rwlock_acquire_writerlock(rw_lock_t* rw) {
	sem_wait(&rw->writelock);
}

void rwlock_release_writerlock(rw_lock_t* rw) {
	sem_wait(&rw->writelock);
}
