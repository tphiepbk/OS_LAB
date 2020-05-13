#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    FILE *fptr;
    fptr = fopen("numbers.txt", "r");
    int arr[10000];
    int index = 0;
    int inNum;
    int flag = fscanf(fptr, "%d", &inNum);
    while (flag != EOF) {
        arr[index] = inNum;
        index++;
        flag = fscanf(fptr, "%d", &inNum); 
    }
    fclose(fptr);

    if (fork() == 0) {
        int countDiv3 = 0;
        for (int i = 0 ; i < index ; i++) {
            if (arr[i] % 3 == 0) {
                countDiv3++;
            }
        }
        printf("%d\n%d\n", countDiv3, getpid());
    }
    else {
        int countDiv2 = 0;
        for (int i = 0 ; i < index ; i++) {
            if (arr[i] % 2 == 0) {
                countDiv2++;
            }
        }
        printf("%d\n%d\n", countDiv2, getpid());
    }
    return 0;
}
