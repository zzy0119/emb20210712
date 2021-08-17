#include <stdio.h>
#include <string.h>

#include "btree.h"

static int charCmp(const void *data1, const void *data2)
{
	const char *d1 = data1;
	const char *d2 = data2;

	return *d1 - *d2;
}

static void charPri(const void *data)
{
	const char *d = data;
	putchar(*d);
}

int main(int argc, char *argv[])
{
	int len, i;
	btree_t *tree;

	if (argc < 2)
		return 1;

	len = strlen(argv[1]);

	btreeHeadInit(&tree, sizeof(char));

	for (i = 0; i < len; i++) {
		treeInsert(tree, argv[1]+i, charCmp);
	}

	treeMidTraval(tree, charPri);

	treeDestroy(tree);

	return 0;
}

