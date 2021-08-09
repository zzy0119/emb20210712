#ifndef __DLIST_H
#define __DLIST_H

struct node_st {
	void *data;
	struct node_st *prev;
	struct node_st *next;
};

typedef struct {
	struct node_st head;
	int size;
}dlist_t;

enum {DLISTHEADINSERT, DLISTTAILINSERT};
typedef void (*print_t)(const void *data);
typedef int (*cmp_t)(const void *data, const void *key);

int dlistHeadInit(dlist_t **dl, int size);

int dlistInsert(dlist_t *dl, const void *data, int way);

void dlistTraval(const dlist_t *dl, print_t pri);

void dlistDestroy(dlist_t *dl);

int dlistDelete(dlist_t *dl, const void *key, cmp_t cmp);

void *dlistSearch(const dlist_t *dl, const void *key, cmp_t cmp);

#endif

