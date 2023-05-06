#include <iostream>

#include "assert.h"
#include "sll.h"

void
test_empty(void) {
  struct sll_elem* head{nullptr};
  assert(0u == sll_length(head));
  assert(INVALID_ARG == sll_remove_last(&head));
  assert(INVALID_ARG == sll_remove_last_n(&head, 1u));
  assert(INVALID_ARG == sll_free(head));

  std::cout << "Empty: OK" << '\n';
}

void
test_one_elem(void) {
  struct sll_elem* head{nullptr};
  char data[]{"Hello world"};
  assert(OK == sll_make_elem(&head, data, sizeof data));
  assert(1u == sll_length(head));
  assert(OK == sll_free(head));

  std::cout << "One element: OK" << '\n';
}

void
test_pushbacks(void) {
  const char* data[]{"Hello world", "Privet Mir", "1 2 3 4 5", "How are you",
                     NULL};

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

  std::cout << "Pushback: OK" << '\n';
}

void
test_removes(void) {
  const char* data[]{"Hello world", "Privet Mir", "1 2 3 4 5", "How are you",
                     NULL};

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

  std::cout << "Remove: OK" << '\n';
}

void
test_merges(void) {
  { assert(INVALID_ARG == sll_merge(nullptr, nullptr)); }

  {
    struct sll_elem* head_first{nullptr};
    assert(OK == sll_make_elem(&head_first, (void*)"Hello world", 12u));
    assert(1u == sll_length(head_first));

    struct sll_elem* head_second{nullptr};
    assert(0u == sll_length(head_second));

    assert(OK == sll_merge(head_first, head_second));
    assert(1u + 0u == sll_length(head_first));
  }

  {
    struct sll_elem* head_first{nullptr};
    assert(OK == sll_make_elem(&head_first, (void*)"Hello world", 12u));
    assert(1u == sll_length(head_first));

    struct sll_elem* head_second{nullptr};
    assert(OK == sll_make_elem(&head_second, (void*)"Privet mir", 11u));
    assert(1u == sll_length(head_second));

    assert(OK == sll_merge(head_first, head_second));
    assert(1u + 1u == sll_length(head_first));
  }

  {
    struct sll_elem* head_first{nullptr};

    assert(OK == sll_make_elem(&head_first, (void*)"123", 3u));
    assert(1u == sll_length(head_first));

    sll_pushback_elem(head_first, (void*)"456", 3u);
    assert(2u == sll_length(head_first));

    sll_pushback_elem(head_first, (void*)"789", 3u);
    assert(3u == sll_length(head_first));

    sll_pushback_elem(head_first, (void*)"012", 3u);
    assert(4u == sll_length(head_first));

    sll_pushback_elem(head_first, (void*)"345", 3u);
    assert(5u == sll_length(head_first));

    sll_pushback_elem(head_first, (void*)"678", 3u);
    assert(6u == sll_length(head_first));

    sll_pushback_elem(head_first, (void*)"901", 3u);
    assert(7u == sll_length(head_first));

    struct sll_elem* head_second{nullptr};

    assert(OK == sll_make_elem(&head_second, (void*)"456", 3u));
    assert(1u == sll_length(head_second));

    sll_pushback_elem(head_second, (void*)"789", 3u);
    assert(2u == sll_length(head_second));

    sll_pushback_elem(head_second, (void*)"012", 3u);
    assert(3u == sll_length(head_second));

    sll_pushback_elem(head_second, (void*)"345", 3u);
    assert(4u == sll_length(head_second));

    assert(OK == sll_merge(head_first, head_second));
    assert(7u + 4u == sll_length(head_first));
  }

  std::cout << "Merge: OK" << '\n';
}

int
main(void) {
  test_empty();
  test_one_elem();
  test_pushbacks();
  test_removes();
  test_merges();
}
