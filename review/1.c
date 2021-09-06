#include <stdio.h>

int i = 1;
int j = 2;
int z = 3;

int main(void)
{
	int i = i;
	int j = j;
	int z = z;

	printf("i:%d\n", i);
	printf("j:%d\n", j);
	printf("z:%d\n", z);

	return 0;
}

