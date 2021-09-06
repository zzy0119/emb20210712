#include <stdio.h>

int main(void)
{
	int arr[] = {11, 12, 13, 14, 15};
	int *ptr = arr;

	*(ptr++) += 100;
	for (int i = 0; i < 5; i++)
		printf("%d\n", arr[i]);

	printf("%d %d\n", *ptr, *(++ptr));


	return 0;
}

