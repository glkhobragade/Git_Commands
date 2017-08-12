#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int done = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

void thr_exit() {
	pthread_mutex_lock(&m);
	done = 1;
	pthread_cond_signal(&c);
    sleep(2);
	pthread_mutex_unlock(&m);
}

void *child(void *arg) {
	printf("child\n");
	thr_exit();
	return NULL;
}

void thr_join() {
	pthread_mutex_lock(&m);
	while (done == 0)
		pthread_cond_wait(&c, &m);  // As this causes the wake up this thread and it acquires the lock automatically,
                                    // it wont go ahead if the signalling side lock is not released.
    
    printf("after cond var is signalled but lock is not yet released"); 
	pthread_mutex_unlock(&m);
}

int main(int argc, char *argv[]) {
	printf("parent: begin\n");
	pthread_t p;
	pthread_create(&p, NULL, child, NULL);
	thr_join();
	printf("parent: end\n");
	return 0;
}
