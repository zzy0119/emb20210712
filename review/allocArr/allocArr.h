#ifndef __ALLOCARR_H
#define __ALLOCARR_H

typedef struct {
	void *p;
	int n;
	int size;
}arr_t;

typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);

int init(arr_t **a, int size);

int add(arr_t *arr, const void *data);

int del(arr_t *arr, const void *key, cmp_t cmp);

void traval(const arr_t *arr, pri_t pri);

void destroy(arr_t *arr);

#endif

