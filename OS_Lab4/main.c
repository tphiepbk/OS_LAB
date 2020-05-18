#include "align_malloc.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    void* aPtr = aligned_malloc(16,64);
    printf("%p", aPtr);
    aligned_free(aPtr);
}