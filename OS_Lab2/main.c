// main.c
#include <stdio.h>
#include "readline.h"
#include "findsubstr.h"

#define MAX 100

int main (int argc, char* argv []) {
    char* fileName = argv[1];
    FILE *f = fopen(fileName, "r");
    char* sub = argv[2];
    int line = 0;
    char str[MAX];
    while (fgets(str, MAX, f) != NULL) {
        if (find_sub_string(str, sub) != -1) {
            printf("line %d: %s", line+1, str);
        }
        line++;
    }
    fclose(f);
}
