#include "ex1.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {
    void* ptr = aligned_malloc(16,64);
    printf("%p", ptr);
}
