#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int global_init_data = 90;
int global_no_init_data;

void print_func() {
    int local_data = 9;
    int* dynamic_data = (int*)malloc(10);
    printf("Process ID : %d\n", getpid());
    printf("Address of the process : \n");
    printf("1. global_init_data = %p\n", &global_init_data);
    printf("2. global_no_init_data = %p\n", &global_no_init_data);
    printf("3. print_func = %p\n", &print_func);
    printf("4. local_data = %p\n", &local_data);
    printf("5. dynamic_data = %p\n", dynamic_data);
}

int main() {
    print_func();
    sleep(1000);
    return 0;
}