#ifndef __STACK_H
#define __STACK_H

typedef struct {
	void *start;
	int capacity;
	int size;
	int top;
}stack_t;

int stackInit(stack_t **s, int size, int capacity);

int stackIsEmpty(const stack_t *s);

int stackIsFull(const stack_t *s);

int stackPush(stack_t *s, const void *data);

int stackPop(stack_t *s, void *data);

void stackDestroy(stack_t *s);

#endif

