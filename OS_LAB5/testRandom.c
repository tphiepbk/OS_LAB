#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double x,y;

    srand(time(NULL));

    for (int i = 0 ; i < 10 ; i++) {
        x = (double)rand()/RAND_MAX*2.0-1.0;
        y = (double)rand()/RAND_MAX*2.0-1.0;
        printf ( "X = %f ; Y = %f\n", x,y);
    }
    return 0;
}