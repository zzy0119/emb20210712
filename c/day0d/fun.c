#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_t)(const void *data1, const void *data2);
int sortArr(void *arr, int nmemb, int size, cmp_t cmp);

static int cmpChar(const void *data1, const void *data2)
{
	const char *d1 = data1;
	const char *d2 = data2;

	return *d2 - *d1;
}

static int cmpInt(const void *data1, const void *data2)
{
	const int *d1 = data1;
	const int *d2 = data2;

	return *d1 - *d2;
}

int main(void)
{
	// 存储strlen函数的地址--->函数指针
	size_t (*p)(const char *);
	p = strlen;
	printf("%ld\n", p("hello"));

	char str[] = "goodbye";

	sortArr(str, strlen(str), sizeof(char), cmpChar);
	puts(str);

	int arr[] = {3,2,1,7,8,9,4,5,10};

	sortArr(arr, sizeof(arr) / sizeof(int), sizeof(int), cmpInt);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

// 任意类型的数组排序
int sortArr(void *arr, int nmemb, int size, cmp_t cmp)
{
	int i, j;

	char *tmp = malloc(size);

	for (i = 0; i < nmemb-1; i++) {
		for (j = 0; j < nmemb-i-1; j++) {
			if (cmp((char *)arr+j*size, (char *)arr+(j+1)*size) > 0) {
				memcpy(tmp, (char *)arr+j*size, size);
				memcpy((char *)arr+j*size, (char *)arr+(j+1)*size, size);
				memcpy((char *)arr+(j+1)*size, tmp, size);
			}
		}
	}
	free(tmp);

	return 0;
}








