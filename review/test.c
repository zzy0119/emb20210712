#include <stdio.h>

int main(void)
{
	int a[] = {1,2,3,4,5};
	int *ptr = a+3;

	printf("%d\n", *(ptr--));


	return 0;
}
