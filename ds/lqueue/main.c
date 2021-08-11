#include <stdio.h>

#include "lqueue.h"

int main(int argc, char *argv[])
{
	lqueue_t *lq;
	int i;
	char deq;

	if (argc < 2)
		return -1;

	lqueueInit(&lq, sizeof(char));

	i = 0;	
	while (argv[1][i]) {
		lqueueEnq(lq, argv[1]+i);
		i++;
	}

	while (!lqueueEmpty(lq)) {
		lqueueDeq(lq, &deq);	
		putchar(deq);
	}
	putchar('\n');

	lqueueDestroy(lq);

	return 0;
}
