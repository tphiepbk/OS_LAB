#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define NUM_OF_THREADS 10

int total_points = 0;
int points_in_circles_of_thread = 0;
int total_points_in_circles = 0;

void* count(void* args) {

    srand(time(NULL));

    points_in_circles_of_thread = 0;
    int points_in_thread = total_points / NUM_OF_THREADS;
    double x,y;
    
    for (int i = 0 ; i < points_in_thread ; i++) {

        x = (double)rand()/RAND_MAX*2.0-1.0;
        y = (double)rand()/RAND_MAX*2.0-1.0;

        if (x*x + y*y <= 1) {
            points_in_circles_of_thread++;
        }
        
    }
    total_points_in_circles += points_in_circles_of_thread;
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    clock_t start = clock();
    if (argc != 2) {
        fprintf(stderr, "Cannot find number of points\n");
        return -1;
    }

    total_points = atoi(argv[1]);
    pthread_t threads[NUM_OF_THREADS];
    for (int i = 0 ; i < NUM_OF_THREADS ; i++) {
        pthread_create(&threads[i], NULL, &count, NULL);
        pthread_join(threads[i], NULL);
    }

    double numPi = 4.0 * total_points_in_circles / total_points;
    printf("Estimated PI = %f\n", numPi);

    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Collapsed Time = %f\n", seconds);
    pthread_exit(0);
}