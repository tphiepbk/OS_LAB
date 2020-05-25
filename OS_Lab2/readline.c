#include "readline.h"

int read_line(char* str) {
    scanf("%s", str);
    int count = 0;
    const char* walker = str;
    while (*walker != '\0') {
        count++;
        walker++;
    }
    return count;
}