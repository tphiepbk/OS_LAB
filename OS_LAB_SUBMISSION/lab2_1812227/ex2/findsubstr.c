#include "findsubstr.h"

int find_sub_string ( const char *str ,const char *sub) {
    const char* walker1 = str;
    const char* walker2 = sub;

    int index = 0;
    int count = 0;
    int subLen = 0;

    while (*walker2 != '\0') {
        subLen++;
        walker2++;
    }
    walker2 = sub;

    while (*walker1 != '\0') {
        if (*walker1 == *walker2) {
            count++;
            walker2++;
            if (count == subLen) return index + 1 - count;
        }
        else {
            if (count != 0 && count < subLen) {
                walker1--;
                index--;
                walker2 = sub;
                count = 0;
            }
        }
        walker1++;
        index++;
    }
    return -1;
}