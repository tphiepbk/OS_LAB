#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void *simple_malloc(size_t size) {
    void *p;
    p = sbrk(0);
    if (sbrk(size) == (void*)-1) return NULL;
    return p;
}

int main() {
    void *p = simple_malloc(10);
    printf("%p",p);
}