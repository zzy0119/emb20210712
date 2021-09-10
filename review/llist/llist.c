#include <stdlib.h>
#include <string.h>

#include "llist.h"

int listheadInit(struct listhead_st **s, int size)
{
	*s = malloc(sizeof(struct listhead_st));
	if (NULL == *s)
		return -1;
	(*s)->head.prev = (*s)->head.next = &(*s)->head;
	(*s)->head.data = NULL;
	(*s)->size = size;

	return 0;
}

static int __insert(struct node_st *prev, struct node_st *next, struct node_st *new)
{
	new->prev = prev;
	new->next = next;
	prev->next = new;
	next->prev = new;
}

int listInsert(struct listhead_st *s, const void *data, int way)
{
	struct node_st *new;

	new = malloc(sizeof(struct node_st));
	if (NULL == new)
		return -1;
	new->data = malloc(s->size);
	if (NULL == new->data) {
		free(new);
		return -1;
	}
	memcpy(new->data, data, s->size);
	if (way == LISTHEADINSERT)
		__insert(&s->head, s->head.next, new);
	else if (way == LISTTAILINSERT)
		__insert(s->head.prev, &s->head, new);

	return 0;
}

static struct node_st *__find(const struct listhead_st *s, const void *key, cmp_t cmp)
{
	struct node_st *cur;

	for (cur = s->head.next; cur != &s->head; cur = cur->next) {
		if (cmp(cur->data, key) == 0)
			return cur;
	}
	return NULL;
}

static void __delete(struct node_st *del)
{
	del->prev->next = del->next;
	del->next->prev = del->prev;
	del->prev = del->next = NULL;
	free(del->data);
	free(del);
}

int listDelete(struct listhead_st *s, const void *key, cmp_t cmp)
{
	struct node_st *f = __find(s, key, cmp);
	if (NULL == f)
		return -1;
	__delete(f);
	return 0;
}

int listIsEmpty(const struct listhead_st *s)
{
	return s->head.prev == &s->head && s->head.next == &s->head;
}

void listTaval(const struct listhead_st *s, pri_t pri)
{
	struct node_st *cur;
	
	for (cur = s->head.next; cur != &s->head; cur = cur->next)
		pri(cur->data);
}

void listDestroy(struct listhead_st *s)
{
	struct node_st *cur;

	for (cur = s->head.next; cur != &s->head; cur = s->head.next) 
		__delete(cur);
	free(s);
}




