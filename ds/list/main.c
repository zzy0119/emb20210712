#include <stdio.h>

#include "list.h"
#define N	10

static void showInt(const void *data)
{
	const int *d = data;

	printf("%d\n", *d);
}

int main(void)
{
	listhead_t *head;
	int arr[N] = {1,7,9,2,4,6,8,5,7,3};

	listheadInit(&head, sizeof(int));

	for (int i = 0; i < N; i++)
		listInsert(head, arr+i, LISTINSERTTAIL);
	listTraval(head, showInt);

	listDestroy(head);

	return 0;
}

