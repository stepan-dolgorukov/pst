#include "sll.h"
#include "assert.h"

void test_one_elem() {
  struct sll_elem* head{nullptr};
  char data[]{"Hello world"};
  assert(OK == sll_make_elem(&head, data, sizeof data));
  assert(OK == sll_free(head));
}

int main(void) {
  test_one_elem();
}
