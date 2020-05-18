#include <stdlib.h>
#include <stdio.h>
#include "ex1.h"

void * aligned_malloc(unsigned int size, unsigned int align) {
    void* p1; 
    void** p2; 
    unsigned int offset = align - 1 + sizeof(void*);
    p1 = (void*)malloc(size + offset);
    if (p1 == NULL || size <= 0) {
        return NULL;
    }
    p2 = (void**)(((size_t)(p1) + offset) & ~(align - 1));
    return p2;
}

void * aligned_free(void *p) {
    free(((void**)p)[-1]); 
    return NULL;
}
