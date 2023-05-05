#include "als.h"
#include <stdio.h>

int*
lsearch(int* begin, int* end, void* elem, size_t elem_size, equator eq) {
  if (NULL == begin) {
    return NULL;
  }

  if (NULL == end) {
    return NULL;
  }

  if (begin >= end) {
    return NULL;
  }

  if (NULL == eq) {
    return NULL;
  }

  while (begin != end) {
    if (eq(begin, elem, elem_size)) {
      return begin;
    }

    ++begin;
  }

  return NULL;
}
