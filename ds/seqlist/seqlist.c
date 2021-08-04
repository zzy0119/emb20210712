#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "seqlist.h"

int seqlistInit(seqlist_t **s, int size)
{
	*s = malloc(sizeof(seqlist_t));
	if (NULL == *s)
		return -1;
	(*s)->p = NULL;
	(*s)->nmemb = 0;
	(*s)->size = size;

	return 0;
}

int seqlistAdd(seqlist_t *s, const void *data)
{
	s->p = realloc(s->p, (s->nmemb+1)*s->size);
	if (s->p == NULL)
		return -1;
	memcpy((char *)s->p + s->nmemb * s->size, data, s->size);
	(s->nmemb)++;

	return 0;
}

void seqlistTraval(const seqlist_t *s, pri_t pri)
{
	int i;

	for (i = 0; i < s->nmemb; i++) {
		pri((char *)s->p + i*s->size);
	}
}

void seqlistDestroy(seqlist_t *s)
{
	free(s->p);
	free(s);
}

// 返回所要查找的元素的地址
static void *__find(const seqlist_t *s, const void *key, cmp_t cmp)
{
	int i;

	for (i = 0; i < s->nmemb; i++)
		if (cmp((char *)s->p+i*s->size, key) == 0)
			return (char *)s->p + i*s->size;

	return NULL;
}

int seqlistDel(seqlist_t *s, const void *key, cmp_t cmp)
{
	void *f;
	char *end, *delNext;

	f = __find(s, key, cmp);	
	if (NULL == f)
		return -1;
	end = (char *)s->p+(s->nmemb*s->size);
	delNext = (char *)f+s->size;
	memcpy(f, (char *)f+s->size, \
			end-delNext);
	s->nmemb--;
	s->p = realloc(s->p, s->nmemb*s->size);
	if (NULL == s->p)
		return -1;
	
	return 0;
}







