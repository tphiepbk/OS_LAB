#include "ex1.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {
    void* ptr = aligned_malloc(1024,1024);
    printf("%p", ptr);
}
