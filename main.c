#include "sll.h"
#include "assert.h"

int main(void) {
  struct sll_elem* head = NULL;

  char data[][32] = {
    "Hello world",
    "Privet mir",
    "Bonjour"
  };

  assert(OK == sll_make_elem(&head, data[0], 32));
  assert(OK == sll_pushback_elem(head, data[0], 32));
  assert(OK == sll_pushback_elem(head, data[1], 32));
  assert(OK == sll_pushback_elem(head, data[2], 32));
  assert(OK == sll_pushback_elem(head, data[1], 32));
  assert(OK == sll_pushback_elem(head, data[2], 32));
  assert(OK == sll_pushback_elem(head, data[0], 32));

  sll_print(head);
  sll_free(head);
}
