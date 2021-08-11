#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char *argv[1])
{
	stack_t *s;
	int n, var;

	if (argc < 2)
		return 1;

	stackInit(&s, sizeof(char), 32);

	n = atoi(argv[1]);

	while (n > 0) {
		var = n % 2;
		stackPush(s, &var);
		n /= 2;
	}

	while (!stackIsEmpty(s)) {
		stackPop(s, &var);
		printf("%d ", var);
	}
	printf("\n");

	stackDestroy(s);

	return 0;
}

