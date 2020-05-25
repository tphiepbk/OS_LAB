#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *printHello(void *threadID) {
    long tID;
    tID = (long)threadID;
    printf("Hello World - Thread ID #%ld\n", tID);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int rc;
    long t;
    for (t = 0 ; t < 5 ; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, printHello, (void*)t);
        if (rc) {
            printf("ERROR return from pthread create() is %d\n", rc);
            exit(-1);
        }
        pthread_join(threads[t], NULL);
    }
    printf("Hello world\n");
    pthread_exit(NULL);
}