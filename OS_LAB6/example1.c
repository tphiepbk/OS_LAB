#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

static volatile int counter = 0;
pthread_mutex_t lock;

void * mythread(void* arg) {
    printf("%s: begin\n", (char*) arg);

    pthread_mutex_lock(&lock);
    for (int i = 0 ; i < 1e7 ; i++) {
        counter = counter + 1;
    }
    pthread_mutex_unlock(&lock);

    printf("%s: done\n", (char*)arg);
    return NULL;
}

int main(int argc, char const *argv[])
{
    /*
    pthread_t p1, p2;
    printf("main: begin (counter = %d)\n", counter);
    pthread_create(&p1, NULL, mythread, "A");
    pthread_create(&p2, NULL, mythread, "B");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("main: done with both (counter = %d)\n", counter);
    return 0;
    */

    pthread_t p1, p2;
    int rc;

    pthread_mutex_init(&lock, NULL);

    printf("main: begin (counter = %d)\n", counter);
    rc = pthread_create(&p1, NULL, mythread, "A"); assert(rc == 0);
    rc = pthread_create(&p2, NULL, mythread, "B"); assert(rc == 0);

    rc = pthread_join(p1, NULL); assert(rc == 0);
    rc = pthread_join(p2, NULL); assert(rc == 0);
    printf("main: done with both (counter = %d)\n", counter);

    return 0;
}
