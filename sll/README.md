# Односвязный список ­— Single Linked List (SLL)

## Функции

+ Создание элемента (узла) списка

```
int sll_make_elem(struct sll_elem** elem, void* data, size_t sz);
```

+ Создание нового элемента, добавление в конец списка

```
int sll_pushback_elem(struct sll_elem* head_elem, void* data, size_t sz);
```

+ Создание нескольких элементов и их добавление в конец списка

```
int sll_pushback_elems(struct sll_elem* head_elem, void** data, size_t* sizes);
```

+ Пометить память, занятую списком, свободной. После вызова
этой функции список можно считается разрушенным

```
int sll_free(struct sll_elem** head_elem);
```

+ Распечатать содержимое списка в стандартный поток вывода.
Каждый узел выводится в новой строке. Сначала выводится адрес узла в памяти, потом полезная нагрузка

```
int sll_print(struct sll_elem* head_elem);
```

+ Удалить последний элемент в списке

```
int sll_remove_last(struct sll_elem** head_elem);
```

+ Удалить последние N элментов в списке, N ≥ 1

```
int sll_remove_last_n(struct sll_elem** head_elem, size_t nelems);
```

+ Вычислить длину списка. Длина вычисляется за линейное время

```
size_t sll_length(struct sll_elem* head_elem);
```

+ Слияние двух списков

```
int sll_merge(struct sll_elem* head_first, struct sll_elem* head_second);
```

+ Линейный поиск элемента в списке. Сравниваются первые `sz` байтов

```
int sll_find(struct sll_elem* head, void* data, size_t sz, struct sll_elem** result);
```