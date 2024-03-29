#include <cassert>
#include <cstdio>
#include <iostream>

#include "als.h"
#include "eq.h"

void
test_integers(void) {
  int data[]{1, 2, 3};

  auto has{[begin = &data[0], end = &data[0] + 3](void* elem_to_search,
                                                  size_t elem_size) {
    void* found{lsearch(begin, end, elem_to_search, elem_size, eq)};
    return end != found;
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

void test_strings(void) {
  constexpr size_t strsz{32u};

  char data[][strsz]{
    "123",
    "456",
  };

  auto has{[begin = &data[0], end = &data[0] + 2](void* elem_to_search,
                                                  size_t elem_size) {
    void* found{lsearch(begin, end, elem_to_search, elem_size, eq)};
    return end != found;
  }};

  {
    char elem_to_search[strsz]{"0"};
    assert(!has(elem_to_search, sizeof elem_to_search));
  }

  {
    char elem_to_search[strsz]{"1"};
    // "1" - это подстрока "123"
    assert(has(elem_to_search, 1u));
  }

  {
    char elem_to_search[strsz]{"123"};
    assert(has(elem_to_search, sizeof elem_to_search));
  }

  {
    char elem_to_search[strsz]{"456"};
    assert(has(elem_to_search, sizeof elem_to_search));
  }

  {
    char elem_to_search[strsz]{"123456"};
    assert(!has(elem_to_search, sizeof elem_to_search));
  }

  {
    char elem_to_search[strsz]{"789"};
    assert(!has(elem_to_search, sizeof elem_to_search));
  }

  std::cout << "Strings: OK" << '\n';
}

void test_arrays(void) {
  constexpr size_t arrsz{4u};

  unsigned data[][arrsz]{{0x9E5280E5, 0x82A67B89, 0x9F0A4675, 0x1DEB2AE5},
                         {0x3F0455F7, 0x7089A716, 0xA9C2E47F, 0x965C1351}};

  auto has{[begin = &data[0], end = &data[0] + 3](void* elem_to_search,
                                                  size_t elem_size) {
    void* found{lsearch(begin, end, elem_to_search, elem_size, eq)};
    return end != found;
  }};

  {
    unsigned elem_to_search[][arrsz]{0x9F0A4675, 0x1DEB2AE5, 0x3F0455F7,
                                     0x7089A716};
    assert(!has(elem_to_search, sizeof elem_to_search));
  }

  {
    unsigned elem_to_search[][arrsz]{0x9F0A4675};
    assert(has(elem_to_search, sizeof(unsigned)));
  }

  {
    unsigned elem_to_search[][arrsz]{0x9E5280E5, 0x82A67B89, 0x9F0A4675,
                                     0x1DEB2AE5};
    assert(has(elem_to_search, sizeof elem_to_search));
  }

  {
    unsigned elem_to_search[][arrsz]{0x3F0455F7, 0x7089A716, 0xA9C2E47F, 0x965C1351};
    assert(has(elem_to_search, sizeof elem_to_search));
  }

  std::cout << "Arrays: OK" << '\n';
}

int
main(void) {
  test_integers();
  test_strings();
  test_arrays();
}
