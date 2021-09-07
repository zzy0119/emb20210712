/*
 1.定义一个动态的整型数组,要求提供的接口有
 <1>int add(int **p, int *n, int elm);
 增加一个新的元素elm, *p是首地址，*n是元素个数
 <2>int del(int **p, int *n, int key);
 key是要删除的元素
 <3>void traval(int *p, int n);
 遍历
 <4>int findMax(int *p, int n, int *max);
 *max是回填的最大值
 */
#include <stdio.h>
#include "intArr.h"

int main(int argc, char **argv)
{
	int *arr = NULL;
	int n = 0;
	int m;

	if (argc < 2)
		return 1;
	for (int i = 0; argv[1][i]; i++) {
		add(&arr, &n, argv[1][i]);
	}
	traval(arr, n);

	if (argc >= 3) {
		for (int i = 0; argv[2][i]; i++)
			del(&arr, &n, argv[2][i]);
	}
	traval(arr, n);

	findMax(arr, n, &m);
	printf("%d\n", m);

	return 0;
}

