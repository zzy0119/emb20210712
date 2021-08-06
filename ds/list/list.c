#include <stdlib.h>
#include <string.h>

#include "list.h"

int listheadInit(listhead_t **l, int size)
{
	*l = malloc(sizeof(listhead_t));
	if (*l == NULL)
		return -1;
	(*l)->head.data = NULL;
	(*l)->head.next = &(*l)->head;
	(*l)->size = size;

	return 0;
}

int listInsert(listhead_t *l, const void *data, int way)
{
	struct node_st *new, *last;

	new = malloc(sizeof(struct node_st));
	if (NULL == new)
		return -1;
	new->data = malloc(l->size);
	if (NULL == new->data) {
		free(new);
		return -1;
	}
	memcpy(new->data, data, l->size);
	// 插入单链表中
	if (way == LISTINSERTHEAD) {
		new->next = l->head.next;	
		l->head.next = new;
	} else if (way == LISTINSERTTAIL) {
		new->next = &l->head;
		for (last = l->head.next; last->next != &l->head; last = last->next)
			;
		last->next = new;
	} else {
		free(new->data);
		free(new);
		return -1;
	}

	return 0;
}

void listTraval(const listhead_t *l, pri_t pri)
{
	struct node_st *p;	

	for (p = l->head.next; p != &l->head; p = p->next)
		pri(p->data);
}

void listDestroy(listhead_t *l)
{
	struct node_st *cur, *curNext;	

	cur = l->head.next;
	while (cur != &l->head) {
		curNext = cur->next;
		free(cur->data);
		free(cur);
		cur = curNext;
	}

	free(l);
}

static struct node_st *__delNodePrev(const listhead_t *l, const void *key, cmp_t cmp)
{
	struct node_st *prev, *cur;
	
	prev = &l->head;
	cur = prev->next;

	while (cur != &l->head) {
		if (cmp(cur->data, key) == 0)
			return prev;
		prev = cur;
		cur = cur->next;
	}

	return NULL;
}

int listDelete(listhead_t *l, const void *key, cmp_t cmp)
{
	struct node_st *prev, *del;

	prev = __delNodePrev(l, key, cmp);
	if (NULL == prev)
		return -1;

	del = prev->next;
	prev->next = del->next;
	del->next = NULL;
	free(del->data);
	free(del);

	return 0;
}

// 查找
void *listSearch(const listhead_t *l, const void *key, cmp_t cmp)
{
	struct node_st *prev;

	prev = __delNodePrev(l, key, cmp);
	if (NULL == prev)
		return NULL;
	return prev->next->data;
}

static void __insertHead(listhead_t *l, struct node_st *newFirst)
{
	newFirst->next = l->head.next;
	l->head.next = newFirst;
}

void listReverse(listhead_t *l)
{
	struct node_st *second, *first;		

	first = l->head.next;
	second = first->next;
	while (first->next != &l->head) {
		first->next = second->next;	
		second->next = NULL;
		__insertHead(l, second);
		second = first->next;
	}
}








