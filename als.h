#ifndef ALS_H
#define ALS_H
#include <stddef.h>

typedef int (*equator)(void* left, void* right, size_t nbytes);

int*
lsearch(int* begin, int* end, void* elem, size_t elem_size, equator eq);

#endif
