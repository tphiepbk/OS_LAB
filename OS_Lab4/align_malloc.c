#include <stdlib.h>
#include <stdio.h>
#include "align_malloc.h"

void * aligned_malloc(unsigned int size, unsigned int align) {
    void *ptr;
    void *p = malloc(size + align - 1 + sizeof(void*));
    if (p == NULL || align <= 0) {
        return NULL;
    }
    else {
        ptr = (void*) (((unsigned int)p + sizeof(void*) + align -1) & ~(align - 1));
        *((void**)((unsigned int)ptr - sizeof(void*))) = p;
        return ptr;
    }
}

void *aligned_free(void *p) {
    void *ptr = *((void**)((size_t)p - sizeof(void*)));
    free(ptr);
    return NULL;
}