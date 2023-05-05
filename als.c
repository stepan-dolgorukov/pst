#include "als.h"
#include <stdio.h>

int* lsearch(int* begin, int* end, int elem, comp comp) {
  while (begin != end) {
    int cmpres = comp(*begin, elem);
    if (cmpres == 0) {
      return begin;
    }

    ++begin;
  }

  return NULL;
}
