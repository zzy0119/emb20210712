#ifndef __LLIST_H
#define __LLIST_H

struct node_st {
	void *data;
	struct node_st *prev, *next;
};

struct listhead_st {
	struct node_st head;
	int size;
};

enum {LISTHEADINSERT, LISTTAILINSERT};
typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);

int listheadInit(struct listhead_st **s, int size);

int listInsert(struct listhead_st *s, const void *data, int way);

int listDelete(struct listhead_st *s, const void *key, cmp_t cmp);

int listIsEmpty(const struct listhead_st *s);

void listTaval(const struct listhead_st *s, pri_t pri);

void listDestroy(struct listhead_st *s);

#endif

