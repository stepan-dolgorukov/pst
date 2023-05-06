#ifndef ALS_H
#define ALS_H

#if defined(__cplusplus)
#include <cstddef>
extern "C" {
#else
#include <stddef.h>
#endif

typedef int (*equator)(void* left, void* right, size_t nbytes);

void*
lsearch(void* begin, void* end, void* elem, size_t elem_size, equator eq);

#if defined(__cplusplus)
}
#endif

#endif
