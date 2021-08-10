#include <stdlib.h>
#include <string.h>

#include "dlist.h"

int dlistHeadInit(dlist_t **dl, int size)
{
	*dl = malloc(sizeof(dlist_t));
	if (NULL ==  *dl)
		return -1;
	(*dl)->head.data = NULL;
	(*dl)->head.prev = (*dl)->head.next = &(*dl)->head;
	(*dl)->size = size;

	return 0;
}

static int __insert(struct node_st *front, struct node_st *behind, struct node_st *new)
{
	new->prev = front;
	new->next = behind;
	front->next = new;
	behind->prev = new;

	return 0;
}

int dlistInsert(dlist_t *dl, const void *data, int way)
{
	struct node_st *new;

	new = malloc(sizeof(struct node_st));
	if (NULL == new)
		return -1;
	new->data = malloc(dl->size);
	if (NULL == new->data) {
		free(new);
		return -1;
	}
	memcpy(new->data, data, dl->size);

	if (way == DLISTHEADINSERT)
		__insert(&dl->head, dl->head.next, new);
	else if (way == DLISTTAILINSERT)
		__insert(dl->head.prev, &dl->head, new);
	else {
		free(new->data);
		free(new);
		return -1;
	}

	return 0;
}

void dlistTraval(const dlist_t *dl, print_t pri)
{
	struct node_st *cur;	

	for (cur = dl->head.next; cur != &dl->head; cur = cur->next) {
		pri(cur->data);
	}
}

static void __destroy(struct node_st *del)
{
	del->prev->next = del->next;
	del->next->prev = del->prev;
	del->prev = del->next = NULL;

	free(del->data);
	free(del);
}

void dlistDestroy(dlist_t *dl)
{
	struct node_st *del;	

	del = dl->head.next;
	while (del != &dl->head) {
		__destroy(del);
		del = dl->head.next;
	}

	free(dl);
}

static struct node_st *__search(const dlist_t *dl, const void *key, cmp_t cmp)
{
	struct node_st *cur;

	for (cur = dl->head.next; cur != &dl->head; cur = cur->next)
		if (cmp(cur->data, key) == 0)
			return cur;
	return NULL;
}

int dlistDelete(dlist_t *dl, const void *key, cmp_t cmp)
{
	struct node_st *f;

	f = __search(dl, key, cmp);
	if (NULL == f)
		return -1;
	__destroy(f);

	return 0;
}

void *dlistSearch(const dlist_t *dl, const void *key, cmp_t cmp)
{
	struct node_st *f;

	f = __search(dl, key, cmp);
	if (NULL == f)
		return NULL;

	return f->data;
}

void *dlistFindMidNode(const dlist_t *dl)
{
	struct node_st *slow, *fast;

	slow = fast = dl->head.next;
	while (fast != &dl->head || fast->next != &dl->head) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow->data;
}

static void __sort(struct node_st *front, struct node_st *behind, struct node_st *mid)
{
	mid->prev = front;
	mid->next = behind;
	front->next = mid;
	behind->prev = mid;
}

void dlistSort(dlist_t *dl, cmp_t cmp)
{
	// 选择排序
	struct node_st *start, *every;
	struct node_st *max;
	struct node_st *maxFront, *maxBehind;

	for (start = dl->head.next; start != &dl->head; start = start->next) {
		max = start;
		for (every = start->next; every != &dl->head; every = every->next) {
			if (cmp(every->data, max->data) > 0)
				max = every;
		}
		if (max != start) {
			maxFront = max->prev;	
			maxBehind = max->next;
			__sort(start->prev, start->next, max);
			__sort(maxFront, maxBehind, start);
		}
	}
	
}


