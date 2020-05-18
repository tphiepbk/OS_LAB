#include <stdio.h>
#include <stdlib.h>

int main() {
    void* p = aligned_alloc(16,64);
    printf("%p", p);
}