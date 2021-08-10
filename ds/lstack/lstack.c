#include <stdio.h>
#include "lstack.h"

int lstackInit(lstack_t **ls, int size)
{
	return dlistHeadInit(ls, size);
}

int lstackIsEmpty(const lstack_t *ls)
{
	return dlistIsEmpty(ls);
}

// 插入--->入栈
int lstackPush(lstack_t *ls, const void *data)
{
	return dlistInsert(ls, data, DLISTHEADINSERT);
}

static int alwayCmp(const void *data, const void *key)
{
	return 0;
}

// 删除--->出栈
int lstackPop(lstack_t *ls, void *data)
{
	return dlistFetch(ls, NULL, alwayCmp, data);
}

void lstackDestroy(lstack_t *ls)
{
	dlistDestroy(ls);
}
