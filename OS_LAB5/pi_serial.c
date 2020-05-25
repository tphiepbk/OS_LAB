#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    clock_t start = clock();

    if (argc != 2) {
        fprintf(stderr, "Cannot find number of points\n");
    }

    double x,y;
    int total_points_in_circle = 0;
    int total_points = atoi(argv[1]);

    srand(time(NULL));

    for (long i = 0 ; i < total_points ; i++) {
        x = (double)rand()/RAND_MAX*2.0-1.0;
        y = (double)rand()/RAND_MAX*2.0-1.0;
        if (x*x + y*y <= 1) {
            total_points_in_circle++;
        }
    }

    double numPi = 4.0 * total_points_in_circle / total_points;
    printf("Estimated PI = %f\n", numPi);

    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Collapsed Time = %f\n", seconds);
}