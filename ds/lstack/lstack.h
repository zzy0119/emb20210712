#ifndef __LSTACK_H
#define __LSTACK_H

#include <dlist.h>

// 链栈--->特殊的链表(在同一端插入删除)
typedef dlist_t lstack_t;

// 初始化栈
int lstackInit(lstack_t **ls, int size);

int lstackIsEmpty(const lstack_t *ls);

// 插入--->入栈
int lstackPush(lstack_t *ls, const void *data);

// 删除--->出栈
int lstackPop(lstack_t *ls, void *data);

void lstackDestroy(lstack_t *ls);

#endif

