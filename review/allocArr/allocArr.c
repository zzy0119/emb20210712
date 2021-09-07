#include <stdlib.h>
#include <string.h>

#include "allocArr.h"

int init(arr_t **a, int size)
{
	*a = malloc(sizeof(arr_t));
	if (NULL == *a)
		return -1;
	(*a)->p = NULL;
	(*a)->n = 0;
	(*a)->size = size;

	return 0;
}

int add(arr_t *arr, const void *data)
{
	arr->p = realloc(arr->p, (arr->n + 1)* arr->size);
	if (NULL == arr->p)
		return -1;
	memcpy((char *)arr->p + arr->n * arr->size, data, arr->size);
	arr->n++;
	return 0;
}

int del(arr_t *arr, const void *key, cmp_t cmp)
{
	int i;

	for (i = 0; i < arr->n; i++) {
		if (cmp((char *)arr->p + i * arr->size, key) == 0) {
			memcpy((char *)arr->p + i * arr->size, \
					(char *)arr->p + (i+1) * arr->size,\
					(arr->n-i-1) * arr->size);
			arr->n--;
			arr->p = realloc(arr->p, arr->n * arr->size);
			if (NULL == arr->p)
				return -1;
			return 0;
		}
	}

	return -1;
}

void traval(const arr_t *arr, pri_t pri)
{
	int i;

	for (i = 0; i < arr->n; i++) {
		pri((char *)arr->p + i * arr->size);
	}
}

void destroy(arr_t *arr)
{
	free(arr->p);
	free(arr);
}



