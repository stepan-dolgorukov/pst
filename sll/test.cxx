#include "sll.h"
#include "assert.h"
#include<iostream>

void test_empty() {
  struct sll_elem* head{nullptr};
  assert(0u == sll_length(head));
  assert(INVALID_ARG == sll_remove_last(&head));
  assert(INVALID_ARG == sll_remove_last_n(&head, 1u));
  assert(INVALID_ARG == sll_free(head));
}

void test_one_elem() {
  struct sll_elem* head{nullptr};
  char data[]{"Hello world"};
  assert(OK == sll_make_elem(&head, data, sizeof data));
  assert(1u == sll_length(head));
  assert(OK == sll_free(head));
}

void test_pushbacks() {
  const char* data[]{
    "Hello world",
    "Privet Mir",
    "1 2 3 4 5",
    "How are you",
    NULL
  };

  {
    struct sll_elem* head{nullptr};
    assert(OK == sll_make_elem(&head, (void*)data[0], 12u));
    assert(1u == sll_length(head));

    assert(OK == sll_pushback_elem(head, (void*)data[1], 11u));
    assert(2u == sll_length(head));

    assert(OK == sll_pushback_elem(head, (void*)data[2], 10u));
    assert(3u == sll_length(head));

    assert(OK == sll_pushback_elem(head, (void*)data[3], 12u));
    assert(4u == sll_length(head));

    assert(OK == sll_free(head));
  }

  {
    struct sll_elem* head{nullptr};
    std::size_t sizes[]{11u, 10u, 12u};

    assert(OK == sll_make_elem(&head, (void*)data[0], 12u));
    assert(1u == sll_length(head));

    assert(OK == sll_pushback_elems(head, (void**)(&data[1]), sizes));
    assert(4u == sll_length(head));

    assert(OK == sll_free(head));
  }
}

void test_removes() {
  const char* data[]{
    "Hello world",
    "Privet Mir",
    "1 2 3 4 5",
    "How are you",
    NULL
  };

  {
    struct sll_elem* head{nullptr};
    std::size_t sizes[]{11u, 10u, 12u};

    assert(OK == sll_make_elem(&head, (void*)data[0], 12u));
    assert(1u == sll_length(head));

    assert(OK == sll_pushback_elems(head, (void**)(&data[1]), sizes));
    assert(4u == sll_length(head));

    assert(OK == sll_remove_last(&head));
    assert(3u == sll_length(head));

    assert(OK == sll_remove_last(&head));
    assert(2u == sll_length(head));

    assert(OK == sll_remove_last(&head));
    assert(1u == sll_length(head));

    assert(OK == sll_pushback_elem(head, (void*)data[2], 10u));
    assert(2u == sll_length(head));

    assert(OK == sll_free(head));
  }

  {
    struct sll_elem* head{nullptr};
    std::size_t sizes[]{11u, 10u, 12u};

    assert(OK == sll_make_elem(&head, (void*)data[0], 12u));
    assert(1u == sll_length(head));

    assert(OK == sll_pushback_elems(head, (void**)(&data[1]), sizes));
    assert(4u == sll_length(head));

    assert(INVALID_ARG == sll_remove_last_n(&head, 5u));
    assert(OK == sll_remove_last_n(&head, 4u));
    assert(0u == sll_length(head));

    assert(INVALID_ARG == sll_free(head));
  }

  {
    struct sll_elem* head{nullptr};
    std::size_t sizes[]{11u, 10u, 12u};

    assert(OK == sll_make_elem(&head, (void*)data[0], 12u));
    assert(1u == sll_length(head));

    assert(OK == sll_remove_last(&head));
    assert(0u == sll_length(head));

    assert(INVALID_ARG == sll_free(head));
  }
}

int main(void) {
  test_empty();
  test_one_elem();
  test_pushbacks();
  test_removes();
}
