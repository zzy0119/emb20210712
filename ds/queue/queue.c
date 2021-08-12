#include <stdlib.h>
#include <string.h>
#include "queue.h"

queue_t *queueInit(int capacity, int size)
{
	queue_t *me;

	me = malloc(sizeof(queue_t));
	if (NULL == me)
		return NULL;
	me->start = calloc(capacity, size);
	if (NULL == me->start) {
		free(me);
		return NULL;
	}
	me->capacity = capacity;
	me->size = size;
	me->front = me->tail = 0;
	
	return me;
}

int queueIsEmpty(const queue_t *q)
{
	return q->front == q->tail;	
}

int queueIsFull(const queue_t *q)
{
	return (q->tail+1) % q->capacity == q->front;
}

int enq(queue_t *q, const void *data)
{
	if (queueIsFull(q))
		return -1;
	memcpy((char *)q->start+q->tail * q->size, data, q->size);
	q->tail = (q->tail+1) % q->capacity;

	return 0;
}

int deq(queue_t *q, void *data)
{
	if (queueIsEmpty(q))
		return -1;
	memcpy(data, (char *)q->start+q->front*q->size, q->size);
	q->front = (q->front+1) % q->capacity;

	return 0;
}

void queueDestroy(queue_t *q)
{
	free(q->start);
	free(q);
}

