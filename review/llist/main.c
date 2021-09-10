#include <stdio.h>
#include "llist.h"

static void show(const void *data)
{
	const char *d = data;
	printf("%c\n", *d);
}

static int cmpChar(const void *data, const void *key)
{
	const char *d = data;
	const char *k = key;

	return *d - *k;
}

int main(int argc, char *argv[])
{
	struct listhead_st *head;
	char delC = 'e';

	if (argc < 2)	
		return 1;

	listheadInit(&head, sizeof(char));

	for (int i = 0; argv[1][i]; i++)
		listInsert(head, argv[1]+i, LISTTAILINSERT);
	listTaval(head, show);

	listDelete(head, &delC, cmpChar);
	listTaval(head, show);

	listDestroy(head);

	return 0;
}
