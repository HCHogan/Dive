#include "./concurrent_queue.c"
#include <pthread.h>
#include <stdio.h>

queue_t myqueue;

pthread_t pth1;
pthread_t pth2;
pthread_t pth3;
pthread_t pth4;

void* work() {
	for(int i = 0; i <= 10000; i++) {
		Queue_Enqueue(&myqueue, i);
	}
	return NULL;
}

int main() {
	Queue_Init(&myqueue);

	pthread_create(&pth1, NULL, work, NULL);
	pthread_create(&pth2, NULL, work, NULL);
	pthread_create(&pth3, NULL, work, NULL);
	pthread_create(&pth4, NULL, work, NULL);

	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);
	pthread_join(pth3, NULL);
	pthread_join(pth4, NULL);

	int last = 0;
	int cnt = 0;
	for(int i = 1; i <= 40000; i++) {
		int tmp;
		Queue_Dequeue(&myqueue, &tmp);
		if(last+1 != tmp) {
			printf("%dG%d\n", last, tmp);
			cnt++;
		}
		last = tmp;
	}
	printf("%d", cnt);

	return 0;

}
