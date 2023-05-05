#include <cassert>
#include <cstdio>
#include <iostream>

#include "als.h"
#include "eq.h"

void
test_integers() {
  int data[]{1, 2, 3};

  auto has{[begin = &data[0], end = &data[0] + 3](void* elem_to_search,
                                                  size_t elem_size) {
    void* found{lsearch(begin, end, elem_to_search, elem_size, eq)};
    return nullptr != found;
  }};

  {
    int elem_to_search{1};
    assert(has(&elem_to_search, sizeof elem_to_search));
  }

  {
    int elem_to_search{2};
    assert(has(&elem_to_search, sizeof elem_to_search));
  }

  {
    int elem_to_search{3};
    assert(has(&elem_to_search, sizeof elem_to_search));
  }

  {
    int elem_to_search{0};
    assert(!has(&elem_to_search, sizeof elem_to_search));
  }

  {
    int elem_to_search{4};
    assert(!has(&elem_to_search, sizeof elem_to_search));
  }

  std::cout << "Integers: OK" << '\n';
}

int
main(void) {
  test_integers();
}
