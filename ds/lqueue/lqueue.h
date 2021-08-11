#ifndef __LQUEUE_H
#define __LQUEUE_H

#include <dlist.h>

typedef dlist_t lqueue_t;

// 特殊的线性结构:一端插入，另一端删除

int lqueueInit(lqueue_t **s, int size);

int lqueueEmpty(const lqueue_t *s);

int lqueueEnq(lqueue_t *s, const void *data);

int lqueueDeq(lqueue_t *s, void *data);

void lqueueDestroy(lqueue_t *s);

#endif

