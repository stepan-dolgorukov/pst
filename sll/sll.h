#ifndef SLL_H
#define SLL_H

#if defined(__cplusplus)
#include <cstddef>
extern "C" {
#else
#include <stddef.h>
#endif

enum ERROR {
  OK = 0,
  BAD_ALLOC,
  INVALID_ARG
};

struct sll_elem {
  struct sll_elem* next;
  struct {
    size_t sz;
    void* data;
  } payload;
};

int
sll_make_elem(struct sll_elem** elem, void* data, size_t sz);

int
sll_pushback(struct sll_elem* head_elem, void* data, size_t sz);

int
sll_pushback_n(struct sll_elem* head_elem, void** data, size_t* sizes);

int
sll_free(struct sll_elem** head_elem);

int
sll_print(struct sll_elem* head_elem);

int
sll_remove_last(struct sll_elem** head_elem);

int
sll_remove_last_n(struct sll_elem** head_elem, size_t nelems);

size_t
sll_length(struct sll_elem* head_elem);

int
sll_merge(struct sll_elem* head_first, struct sll_elem* head_second);

int
sll_find(struct sll_elem* head, void* data, size_t sz, struct sll_elem** result);

#if defined(__cplusplus)
}
#endif

#endif
