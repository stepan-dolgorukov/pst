#ifndef ALS_H
#define ALS_H

typedef int(*comp)(int left, int right);
int* lsearch(int* begin, int* end, int elem, comp comp);

#endif
