#ifndef EQ_H
#define EQ_H

#if defined(__cplusplus)
#include <cstddef>
extern "C" {
#else
#include <stddef.h>
#endif

int eq(void* left, void* right, size_t nbytes);

#if defined(__cplusplus)
}
#endif

#endif
