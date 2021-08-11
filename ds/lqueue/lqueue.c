#include <stdio.h>
#include "lqueue.h"

int lqueueInit(lqueue_t **s, int size)
{
	return dlistHeadInit(s, size);
}

int lqueueEmpty(const lqueue_t *s)
{
	return dlistIsEmpty(s);
}

int lqueueEnq(lqueue_t *s, const void *data)
{
	return dlistInsert(s, data, DLISTTAILINSERT);
}

static int alwaysCmp(const void *data, const void *key)
{
	return 0;
}

int lqueueDeq(lqueue_t *s, void *data)
{
	return dlistFetch(s, NULL, alwaysCmp, data);
}

void lqueueDestroy(lqueue_t *s)
{
	dlistDestroy(s);
}

