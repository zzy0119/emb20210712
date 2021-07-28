/*
 定义一个函数，将一个整型数组的最大值和最小值返回
 可以通过参数返回
 */
#include <stdio.h>

int maxMinValue(int *arr, int n, int *max, int *min);
int main(void)
{
	int arr[] = {3, 1, 10, 8, 2, 9, 144, 45, 0};// arr常量值，首元素的地址不能改
	int maxValue, minValue;

	maxMinValue(arr, sizeof(arr) / sizeof(int), &maxValue, &minValue);
	printf("最大值:%d\n, 最小值:%d\n", maxValue, minValue);


	return 0;
}

int maxMinValue(int *arr/*指针变量,值可以改变*/, int n, int *max, int *min)
{
	int i;

	*max = *min = arr[0];
	for (i = 1; i < n; i++)	{
		if (*(arr+i) > *max)
			*max = arr[i];
		if (arr[i] < *min)
			*min = arr[i];
	}

	return 0;
}


