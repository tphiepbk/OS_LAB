#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <unistd.h>

void * aligned_malloc(unsigned int size, unsigned int align);

void * aligned_free(void * ptr);