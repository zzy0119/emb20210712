#include <stdlib.h>
#include <string.h>
#include "stack.h"

int stackInit(stack_t **s, int size, int capacity)
{
	*s = malloc(sizeof(stack_t));
	if (NULL == *s)
		return -1;
	(*s)->start = calloc(capacity, size);
	if (NULL == (*s)->start) {
		free(*s);
		return -1;
	}
	(*s)->capacity = capacity;
	(*s)->size = size;
	(*s)->top = 0;

	return 0;
}

int stackIsEmpty(const stack_t *s)
{
	return s->top == 0;
}

int stackIsFull(const stack_t *s)
{
	return s->top == s->capacity;
}

int stackPush(stack_t *s, const void *data)
{
	if (stackIsFull(s))
		return -1;
	memcpy((char *)s->start+s->top*s->size, data, s->size);
	s->top ++;

	return 0;
}

int stackPop(stack_t *s, void *data)
{
	if (stackIsEmpty(s))
		return -1;
	s->top--;
	memcpy(data, (char *)s->start+s->top*s->size, s->size);

	return 0;
}

void stackDestroy(stack_t *s)
{
	free(s->start);
	free(s);
}

