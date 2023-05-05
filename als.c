#include "als.h"
#include <stdio.h>

int* lsearch(int* begin, int* end, int elem, comp comp) {
  if (NULL == begin) {
    return NULL;
  }

  if (NULL == end) {
    return NULL;
  }

  if (begin >= end) {
    return NULL;
  }

  if (NULL == comp) {
    return NULL;
  }

  while (begin != end) {
    int cmpres = comp(*begin, elem);
    if (cmpres == 0) {
      return begin;
    }

    ++begin;
  }

  return NULL;
}
