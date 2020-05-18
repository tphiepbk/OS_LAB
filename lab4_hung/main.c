#include "ex1.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    void* p = aligned_malloc(16,64);
    printf("%p", p);
}
