#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*cmp_t)(const void *d1, const void *d2);

void mysort(void *a, int n, int size, cmp_t cmp);
int cmpInt(const void *data1, const void *data2)
{
	const int *d1 = data1;
	const int *d2 = data2;

	return *d2 - *d1;
}

int cmpStr(const void *data1, const void *data2)
{
	char *const *d1 = data1;
	char *const *d2 = data2;

	return strcmp(*d1, *d2);
}

int main(int argc, char *argv[])
{
	int arr[10] = {5,1,7,8,2,6,3,8,4,9}; 

	mysort(arr, 10, sizeof(int), cmpInt);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	mysort(argv, argc, sizeof(char *), cmpStr);
	for (int i = 0; i < argc; i++)
		puts(argv[i]);

	return 0;
}


