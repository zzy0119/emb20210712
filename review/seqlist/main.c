#include <stdio.h>

#include "seqlist.h"

static int charCmp(const void *data, const void *key)
{
	const char *d = data;
	const char *k = key;

	return *d - *k;
}

static void show(const void *data)
{
	const char *d = data;

	printf("%c\n", *d);
}

#define DEBUG

int main(int argc, char *argv[])
{
	int i;
	seqlist_t *list = NULL;;

	if (argc < 2)			
		return 1;

	seqlistInit(&list, sizeof(char), 2);

	for (i = 0; argv[1][i]; i++)
		seqlistSortInsert(list, argv[1]+i, charCmp);
#undef 	DEBUG
#ifndef DEBUG
	printf("[%d]debug...\n", __LINE__);
#endif
	seqlistTraval(list, show);
#ifndef DEBUG
	printf("[%d]debug...\n", __LINE__);
#endif

	char del = 'e';
	seqlistDelete(list, &del, charCmp);
	seqlistTraval(list, show);

	seqlistDestroy(list);

	return 0;
}

