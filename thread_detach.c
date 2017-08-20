#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *thread_func(void *arg);

int main(int argc, char **argv)
{
    int s;
    void *res;
    pthread_t t1;

    s = pthread_create(&t1, NULL, thread_func, "Hello World\n");

    if (s != 0)
        printf("Err\n");

    printf("In Main()\n");

    //s = pthread_detach(t1);
    //pthread_join(t1, NULL);

    if (s != 0)
        printf("Err\n");
    
    printf("waiting for the thread to complete without using pthread_join");
    pthread_exit(0);
    printf("Main Exiting\n");
    return 0;
}

void *thread_func(void *arg)
{
    char *s = (char *)arg;
    printf("%s", s);
    sleep(5);
    printf("Inside thread after sleep\n");
}
