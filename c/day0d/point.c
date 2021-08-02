#include <stdio.h>

int main(void)
{
	int n = 10;
	int *p = &n;
	int **pp = &p; // pp 二级指针
	int arr[] = {1, 9, 3};

	**pp = 100;
	printf("n:%d\n", n);

	// arr-->int *
	// int a[2][3]; a--->int *[3]
	int (*q)[3] = &arr; // int *[3] 数组指针
	printf("%d\n", *(*q+1));

	return 0;
}

