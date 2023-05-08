#include <cstddef>
#include <iostream>

#include "assert.h"
#include "sll.h"

void
test_empty(void) {
  struct sll_elem* head{nullptr};
  assert(0u == sll_length(head));
  assert(INVALID_ARG == sll_remove_last(&head));
  assert(INVALID_ARG == sll_remove_last_n(&head, 1u));
  assert(INVALID_ARG == sll_free(&head));

  std::cout << "Empty: OK" << '\n';
}

void
test_make_elem(void) {
  struct sll_elem* head{nullptr};
  char data[]{"Hello world"};
  assert(OK == sll_make_elem(&head, data, sizeof data));
  assert(1u == sll_length(head));
  assert(OK == sll_free(&head));

  std::cout << "One element: OK" << '\n';
}

void
test_pushback(void) {
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

    assert(OK == sll_free(&head));
  }

  {
    struct sll_elem* head{nullptr};
    std::size_t sizes[]{11u, 10u, 12u};

    assert(OK == sll_make_elem(&head, (void*)data[0], 12u));
    assert(1u == sll_length(head));

    assert(OK == sll_pushback_elems(head, (void**)(&data[1]), sizes));
    assert(4u == sll_length(head));

    assert(OK == sll_free(&head));
  }

  std::cout << "Pushback: OK" << '\n';
}

void
test_remove(void) {
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

    assert(OK == sll_free(&head));
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

    assert(INVALID_ARG == sll_free(&head));
  }

  {
    struct sll_elem* head{nullptr};
    std::size_t sizes[]{11u, 10u, 12u};

    assert(OK == sll_make_elem(&head, (void*)data[0], 12u));
    assert(1u == sll_length(head));

    assert(OK == sll_remove_last(&head));
    assert(0u == sll_length(head));

    assert(INVALID_ARG == sll_free(&head));
  }

  std::cout << "Remove: OK" << '\n';
}

void
test_merge(void) {
  { assert(INVALID_ARG == sll_merge(nullptr, nullptr)); }

  {
    struct sll_elem* head_first{nullptr};
    assert(OK == sll_make_elem(&head_first, (void*)"Hello world", 12u));
    assert(1u == sll_length(head_first));

    struct sll_elem* head_second{nullptr};
    assert(0u == sll_length(head_second));

    assert(OK == sll_merge(head_first, head_second));
    assert(1u + 0u == sll_length(head_first));

    assert(OK == sll_free(&head_first));
    assert(nullptr == head_first);

    assert(INVALID_ARG == sll_free(&head_second));
    assert(nullptr == head_second);
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

    assert(OK == sll_free(&head_first));
    assert(nullptr == head_first);
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

    assert(OK == sll_free(&head_first));
    assert(nullptr == head_first);
  }

  std::cout << "Merge: OK" << '\n';
}

void test_find(void) {
  {
    struct sll_elem* head{nullptr};
    assert(INVALID_ARG == sll_find(head, nullptr, 0u, nullptr));
  }

  {
    struct sll_elem* head{nullptr};
    assert(OK == sll_make_elem(&head, (void*)"1", 2u));

    assert(INVALID_ARG == sll_find(head, nullptr, 1u, nullptr));
    assert(INVALID_ARG == sll_find(head, (void*)"1", 0u, nullptr));
    assert(INVALID_ARG == sll_find(head, (void*)"1", 2u, nullptr));

    {
      struct sll_elem* find_result{nullptr};
      assert(INVALID_ARG == sll_find(head, (void*)"1", 0u, &find_result));
      assert(INVALID_ARG == sll_find(head, nullptr, 2u, &find_result));
    }

    {
      struct sll_elem* find_result{head};
      assert(INVALID_ARG == sll_find(head, (void*)"1", 2u, &find_result));
    }

    {
      struct sll_elem* find_result{nullptr};
      assert(OK == sll_find(head, (void*)"Hello world!", 13u, &find_result));
      assert(nullptr == find_result);
    }

    // Ни у какого элемента в списке нет такого размера
    {
      struct sll_elem* find_result{nullptr};
      assert(OK == sll_find(head, (void*)"1", 3u, &find_result));
      assert(nullptr == find_result);
    }

    // Сравнение первых 2 байтов
    {
      struct sll_elem* find_result{nullptr};
      assert(OK == sll_find(head, (void*)"1", 2u, &find_result));
      assert(head == find_result);
    }

    // Сравнение первого байта
    {
      struct sll_elem* find_result{nullptr};
      assert(OK == sll_find(head, (void*)"1", 1u, &find_result));
      assert(head == find_result);
    }

    // Элемента со строкой "2" в списке нет
    {
      struct sll_elem* find_result{nullptr};
      assert(OK == sll_find(head, (void*)"2", 1u, &find_result));
      assert(nullptr == find_result);
    }

    assert(OK == sll_free(&head));
  }

  {
    struct sll_elem* find_result[5]{nullptr};
    struct sll_elem* head{nullptr};

    assert(OK == sll_make_elem(&head, (void*)"1", 2u));
    assert(OK == sll_pushback_elem(head, (void*)"2", 2u));
    assert(OK == sll_pushback_elem(head, (void*)"3", 2u));
    assert(OK == sll_pushback_elem(head, (void*)"4", 2u));

    assert(OK == sll_find(head, (void*)"1", 2u, &find_result[0]));
    assert(head == find_result[0]);

    assert(OK == sll_find(head, (void*)"2", 2u, &find_result[1]));
    assert(head->next == find_result[1]);

    assert(OK == sll_find(head, (void*)"3", 2u, &find_result[2]));
    assert(head->next->next == find_result[2]);

    assert(OK == sll_find(head, (void*)"4", 2u, &find_result[3]));
    assert(head->next->next->next == find_result[3]);

    assert(OK == sll_find(head, (void*)"5", 2u, &find_result[4]));
    assert(nullptr == find_result[4]);

    assert(OK == sll_free(&head));
  }

  std::cout << "Find: OK" << '\n';
}

int
main(void) {
  test_empty();
  test_make_elem();
  test_pushback();
  test_remove();
  test_merge();
  test_find();
}