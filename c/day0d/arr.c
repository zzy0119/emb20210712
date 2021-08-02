#include <stdio.h>

// 指针数组:存储指针变量的数组

int main(int argc, char *argv[])
{
	char *arr[3] = {"hello", "embedded", "china"};
	char **p = arr;
	int i;

	for (i = 0; i < 3; i++) {
		puts(arr[i]);
	}

	for (i = 0; /*i < argc*/argv[i]!=NULL; i++)
		puts(argv[i]);

	return 0;
}

