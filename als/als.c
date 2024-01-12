#include "als.h"
#include <stdio.h>

void*
lsearch(void* begin, void* end, void* elem, size_t elem_size, equator eq) {
  if (NULL == begin) {
    return end;
  }

  if (NULL == end) {
    return end;
  }

  if (begin >= end) {
    return end;
  }

  if (NULL == eq) {
    return end;
  }

  while (begin != end) {
    if (eq(begin, elem, elem_size)) {
      return begin;
    }

    begin += elem_size;
  }

  return end;
}
