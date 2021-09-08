#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "seqlist.h"

int seqlistInit(seqlist_t **seqlist, int size, int capacity)
{
	*seqlist = malloc(sizeof(seqlist_t));
	if (NULL == *seqlist)
		return -1;
	(*seqlist)->nmemb = 0;
	(*seqlist)->start = calloc(capacity, size);
	if (NULL == (*seqlist)->start) {
		free(*seqlist);
		return -1;
	}
	(*seqlist)->capacity = capacity;
	(*seqlist)->size = size;

	return 0;
}

static int spaceAlloc(seqlist_t *s)
{
	if (s->nmemb == s->capacity) {
		s->capacity += INCREACE;
		s->start = realloc(s->start, s->capacity);
		if (NULL == s->start)
			return -1;
	}

	return 0;
}

int seqlistInsert(seqlist_t *s, const void *data)
{
	spaceAlloc(s);

	memcpy((char *)s->start + s->nmemb * s->size, data, s->size);
	s->nmemb++;

	return 0;
}

int seqlistDelete(seqlist_t *s, const void *key, cmp_t cmp)
{
	int i;
	char *tmp;

	for (i = 0; i < s->nmemb; i++) {
		tmp = (char *)s->start + i * s->size;
		if (cmp(tmp, key) == 0) {
			memcpy(tmp, tmp + s->size, (s->nmemb - (i + 1)) * s->size);
			s->nmemb--;
			if (s->nmemb < s->capacity-INCREACE) {
				s->capacity -= INCREACE;
				s->start = realloc(s->start, s->size * s->capacity);
			}
			// if error
			return 0;
		}
	}

	return -1;
}

void seqlistTraval(const seqlist_t *s, pri_t pri)
{
	for (int i = 0; i < s->nmemb; i++)
		pri((char *)s->start + i * s->size);
}

int seqlistSortInsert(seqlist_t *s, const void *data, cmp_t cmp)
{
	int i;
	char *tmp;

	spaceAlloc(s);

	for (i = 0; i < s->nmemb; i++) {
		tmp = (char *)s->start + s->size * i;
		if (cmp(tmp, data) > 0) {
			memmove(tmp+s->size, tmp, (s->nmemb - i) * s->size);	
			break;
		}
	}
	if (i == 0 || i == s->nmemb)
		tmp = (char *)s->start + i * s->size;
	memcpy(tmp, data, s->size);
	s->nmemb ++;

	return 0;
}

void seqlistDestroy(seqlist_t *s)
{
	free(s->start);
	free(s);
}

void seqlistSort(seqlist_t *s, cmp_t cmp)
{
	int i, j;
	int min;
	void *tmp = malloc(s->size);

	for (i = 0; i < s->nmemb - 1; i++) {
		min = i;	
		for (j = i + 1; j < s->nmemb; j++) {
			if (cmp((char *)s->start + j * s->size, \
						(char *)s->start + min * s->size) < 0)
				min = j;
		}
		if (min != i) {
			memcpy(tmp, (char *)s->start + i * s->size, s->size);	
			memcpy((char *)s->start + i * s->size, \
					(char *)s->start + min * s->size, s->size);
			memcpy((char *)s->start + min * s->size, tmp, s->size);
		}
	}
	free(tmp);
}

void *seqlistBinarySearch(const seqlist_t *s, const void *key, cmp_t cmp)
{
	int low, high, mid;		
	int ret;
	
	low = 0;
	high = s->nmemb-1;

	while (low <= high) {
		mid = (low + high) / 2;
		ret = cmp((char *)s->start + mid * s->size, key);
		if (ret > 0) {
			high = mid - 1;	
		} else if (ret < 0) {
			low = mid + 1;
		} else 
			return (char *)s->start + mid * s->size;
	}
		
	return NULL;
}








