#ifndef __QUEUE_H
#define __QUEUE_H

// 顺序队列
typedef struct {
	void *start;
	int capacity;
	int size;
	int front;
	int tail;
}queue_t;

queue_t *queueInit(int capacity, int size);

int queueIsEmpty(const queue_t *q);

int queueIsFull(const queue_t *q);

int enq(queue_t *q, const void *data);

int deq(queue_t *q, void *data);

void queueDestroy(queue_t *q);

#endif

