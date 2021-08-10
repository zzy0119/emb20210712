#include <stdio.h>

#include "lstack.h"

int main(void)
{
	int i;
	lstack_t *lsk;

	lstackInit(&lsk, sizeof(int));

	for (i = 1; i <= 10; i++) {
		lstackPush(lsk, &i);
	}

	while (!lstackIsEmpty(lsk)) {
		lstackPop(lsk, &i);
		printf("%d\n", i);
	}

	lstackDestroy(lsk);

	return 0;
}

