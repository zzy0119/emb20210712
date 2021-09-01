#include <stdio.h>

int main(void)
{
	int arr[] = {1,2,3,4,5};	

	return 0;
}

// 整型--->每个元素4bytes
int maxArr(int a[], int n)
{
	int m = a[0];

	for (int i = 1; i < n; i++)
		if (*(a+i) > m)
			m = a[i];
	return m;
}

int maxArr2(int a[], int n, int *max)
{
	*max = a[0];

	for (int i = 1; i < n; i++)
		if (*(a+i) > *max)
			*max = a[i];
	return 0;
}
typedef int (*cmp_t)(const void *data1, const void *data2);
int maxArr3(void *a, int n, int size, void *max, cmp_t cmp)
{
	int i;

	memcpy(max, a, size);	
	for (i = 0; i < n; i++) {
		if (cmp((char *)a + i * size, max) > 0)
			memcpy(max, (char *)a+i*size, size);
	}

	return 0;
}







