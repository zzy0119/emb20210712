#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int add(int **p, int *n, int elm)
{
	*p = realloc(*p, (*n+1) * sizeof(int));
	if (NULL == *p)
		return -1;

	(*p)[*n] = elm;

	(*n)++;

	return 0;
}

int del(int **p, int *n, int key)
{
	int i;

	for (i = 0; i < *n; i++) {
		if ((*p)[i] == key)
			break;
	}
	if (i < *n) {
		memmove(*p + i, *p + (i + 1), \
				(*n - (i + 1)) * sizeof(int));
		(*n)--;
		*p = realloc(*p, (*n) * sizeof(int));
		return 0;
	}
	return -1;
}

void traval(int *p, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%d ", p[i]);	
	}
	printf("\n");
}

int findMax(int *p, int n, int *max)
{
	int i;

	*max = p[0];
	for (i = 1; i < n; i++)
		if (*max < p[i])
			*max = p[i];

	return 0;
}

int addSort(int **p, int *n, int elm)
{
	int i;

	*p = realloc(*p, (*n + 1) * sizeof(int));
	// if error
	for (i = 0; i < *n; i++) {
		if ((*p)[i] > elm)
			break;
	}
	memove(*p + i + 1, *p + i, (*n - i) * sizeof(int));	
	(*p)[i] = elm;
	(*n)++;
	
	return 0;
}



