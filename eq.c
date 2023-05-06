#include "eq.h"

#if defined(__cplusplus)
#include <cstddef>
extern "C" {
#else
#include <stddef.h>
#endif

int eq(void* left, void* right, size_t nbytes) {
  if (NULL == left || NULL == right) {
    return 0;
  }

  if (0u == nbytes) {
    return 0;
  }

  while (*(char*)left == *(char*)right && nbytes--) {
    ++left;
    ++right;
  }
  return 0u == nbytes;
}

#if defined(__cplusplus)
}
#endif
