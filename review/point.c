#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(int *m, int *n);
void swap2(void *data1, void *data2, int size);

int main(int argc, char *argv[])
{
	if (argc < 3)
		return 1;
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);

	test(&m, &n);
	printf("m:%d, n:%d\n", m, n);

	swap2(&m, &n, sizeof(int));
	printf("m:%d, n:%d\n", m, n);

	return 0;
}

void test(int *m, int *n)
{
	int t = *m;
	*m = *n;
	*n = t;
}

void swap2(void *data1, void *data2, int size)
{
	void *p = malloc(size);

	memcpy(p, data1, size);
	memcpy(data1, data2, size);
	memcpy(data2, p, size);
	free(p);
}

