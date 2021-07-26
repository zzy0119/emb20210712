/*
 数组:
 	一维数组定义，初始化，赋值，遍历
		相同类型元素的集合
	排序算法:冒泡，选择，直接插入
	字符数组和字符串
	多维数组
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define N	10

int main(void)
{
	// 定义数组
	int score[N];
	// 初始化
	int arr[5] = {1,2,3,4,5};
	int i;
	int max, min;

	srand(getpid());
	// 赋值--->下标
	for (i = 0; i < N; i++) {
		score[i] = rand() % 100;
		printf("%d ", score[i]);
	}
	printf("\n");

	min = max = score[0];
	for (i = 1; i < N; i++) {
		if (score[i] > max)
			max = score[i];
		if (score[i] < min)
			min = score[i];
	}
	printf("max:%d, min:%d\n", max, min);

	return 0;
}

