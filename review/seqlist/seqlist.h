#ifndef __SEQLIST_H
#define __SEQLIST_H

#define INCREACE	10

typedef struct {
	void *start;
	int nmemb;
	int size;
	int capacity;
}seqlist_t;

typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);

// seqlist_t *seqlistInit(int size, int capacity);
int seqlistInit(seqlist_t **seqlist, int size, int capacity);

int seqlistInsert(seqlist_t *s, const void *data);

int seqlistDelete(seqlist_t *s, const void *key, cmp_t cmp);

void seqlistTraval(const seqlist_t *s, pri_t pri);

int seqlistSortInsert(seqlist_t *s, const void *data, cmp_t cmp);

void seqlistSort(seqlist_t *s, cmp_t cmp);

void seqlistDestroy(seqlist_t *s);

void *seqlistBinarySearch(const seqlist_t *s, const void *data, cmp_t cmp);

#endif

