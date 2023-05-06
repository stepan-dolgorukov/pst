#include "sll.h"
#include <stdlib.h>
#include <stdio.h>

int sll_make_elem(struct sll_elem** elem, void* data, size_t sz) {
  if (NULL == elem) {
    return INVALID_ARG;
  }

  if (NULL != *elem) {
    return INVALID_ARG;
  }

  if (NULL == data) {
    return INVALID_ARG;
  }

if (0u == sz) {
  return INVALID_ARG;
}

  *elem = malloc(sizeof(struct sll_elem));

  if (NULL == elem) {
    return BAD_ALLOC;
  }

  (*elem)->payload.data = data;
  (*elem)->payload.sz = sz;

  return OK;
}

int sll_pushback_elem(struct sll_elem* head_elem, void* data, size_t sz) {

  if (NULL == head_elem) {
    return INVALID_ARG;
  }

  if (NULL == data) {
    return INVALID_ARG;
  }

  if (0u == sz) {
    return INVALID_ARG;
  }

  while (NULL != head_elem->next) {
    head_elem = head_elem->next;
  }

  struct sll_elem* elem = malloc(sizeof(struct sll_elem));

  if (NULL == elem) {
    return BAD_ALLOC;
  }

  elem->payload.data = data;
  elem->payload.sz = sz;

  head_elem->next = elem;
  return OK;
}

int sll_free(struct sll_elem* head_elem) {
  if (NULL == head_elem) {
    return INVALID_ARG;
  }

  while (head_elem) {
    struct sll_elem* next = head_elem->next;
    free(head_elem);
    head_elem = next;
  }

  return OK;
}

int sll_print(struct sll_elem* head_elem) {
  if (NULL == head_elem) {
    return INVALID_ARG;
  }

  while (NULL != head_elem) {
    printf("%p ", head_elem);
    for (size_t i = 0u; i < head_elem->payload.sz; ++i) {
      printf("%X ", *((char*)head_elem->payload.data + i));
    }

    putchar('\n');
    head_elem = head_elem->next;
  }

  return OK;
}