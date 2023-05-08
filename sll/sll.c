#include "sll.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
sll_make_elem(struct sll_elem** elem, void* data, size_t sz) {
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
  (*elem)->next = NULL;

  return OK;
}

int
sll_pushback_elem(struct sll_elem* head_elem, void* data, size_t sz) {
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
  elem->next = NULL;

  head_elem->next = elem;
  return OK;
}

int
sll_pushback_elems(struct sll_elem* head_elem, void** data, size_t* sizes) {
  if (NULL == head_elem) {
    return INVALID_ARG;
  }

  if (NULL == data) {
    return INVALID_ARG;
  }

  if (NULL == sizes) {
    return INVALID_ARG;
  }

  while (NULL != *data) {
    sll_pushback_elem(head_elem, *data, *sizes);
    ++data;
    ++sizes;
  }

  return OK;
}

int
sll_free(struct sll_elem** head_elem) {
  if (NULL == head_elem) {
    return INVALID_ARG;
  }

  if (NULL == *head_elem) {
    return INVALID_ARG;
  }

  while (NULL != *head_elem) {
    struct sll_elem* next = (*head_elem)->next;
    free(*head_elem);
    (*head_elem) = next;
  }

  return OK;
}

int
sll_print(struct sll_elem* head_elem) {
  if (NULL == head_elem) {
    printf("<Empty>\n");
    return OK;
  }

  while (NULL != head_elem) {
    printf("%p ", head_elem);
    for (size_t i = 0u; i < head_elem->payload.sz; ++i) {
      const char* data = (const char*)head_elem->payload.data;
      printf("%X ", data[i]);
    }

    putchar('\n');
    head_elem = head_elem->next;
  }

  return OK;
}

int sll_remove_last(struct sll_elem** head_elem) {
  if (NULL == head_elem) {
    return INVALID_ARG;
  }

  if (NULL == *head_elem) {
    return INVALID_ARG;
  }

  struct sll_elem* parent = NULL;
  while (NULL != (*head_elem)->next) {
    parent = *head_elem;
    head_elem = &((*head_elem)->next);
  }

  if (NULL == parent) {
    free(*head_elem);
    *head_elem = NULL;
  }

  else {
    free(parent->next);
    parent->next = NULL;
  }

  return OK;
}

int
sll_remove_last_n(struct sll_elem** head_elem, size_t nelems) {
  if (NULL == head_elem) {
    return INVALID_ARG;
  }

  if (NULL == *head_elem) {
    return INVALID_ARG;
  }

  if (0u == nelems || sll_length(*head_elem) < nelems) {
    return INVALID_ARG;
  }

  while (nelems--) {
    sll_remove_last(head_elem);
  }

  return OK;
}

size_t
sll_length(struct sll_elem* head_elem) {
  size_t length = 0u;

  while (head_elem && ++length) {
    head_elem = head_elem->next;
  }

  return length;
}

int sll_merge(struct sll_elem* head_first, struct sll_elem* head_second) {
  if (NULL == head_first) {
    return INVALID_ARG;
  }

  while (NULL != head_first->next) {
    head_first = head_first->next;
  }

  head_first->next = head_second;
  return OK;
}

int
sll_find(struct sll_elem* head, void* data, size_t sz, struct sll_elem** result) {
  if (NULL == head) {
    return INVALID_ARG;
  }

  if (NULL == data) {
    return INVALID_ARG;
  }

  if (0u == sz) {
    return INVALID_ARG;
  }

  if (NULL == result) {
    return INVALID_ARG;
  }

  if (NULL != *result) {
    return INVALID_ARG;
  }

  while (NULL != head) {
    if (head->payload.sz >= sz) {
      if (0 == memcmp(head->payload.data, data, sz)) {
        *result = head;
        return OK;
      }
    }

    head = head->next;
  }

  return OK;
}