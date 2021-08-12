#include <stdio.h>
#include <string.h>

#include "queue.h"

int main(int argc, char *argv[])
{
	queue_t *myq;	
	int i;

	if (argc < 2)
		return 1;

	myq = queueInit(strlen(argv[1])+1, sizeof(char));
	if (NULL == myq)
		return -1;
	
	i = 0;
	while (argv[1][i]) {
		enq(myq, argv[1]+i);
		i ++;
	}

	while (!queueIsEmpty(myq)) {
		deq(myq, &i);
		putchar(i);
	}
	putchar('\n');

	queueDestroy(myq);

	return 0;
}
