#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/*
1.定义一个由10个随机整型变量组成的数组,求数组中所有元素的平均值
2.随机产生10个整型变量组成数组，将此数组中的最大元素作为第一个元素，最小元素作为第二个元素
 */
#define N	10

int main(void)
{
	int arr[N] = {}; // 初始化为0	
	int i;
	int sum = 0;
	int max_i, min_i;
	int tmp;

	srand(getpid());
	for (i = 0; i < N; i++) {
		arr[i] = rand() % 20;
		printf("%d ", arr[i]);
		sum += arr[i];
	}
	printf("\n");

	printf("avg:%d\n", sum / N);

	//
	max_i = min_i = 0;
	for (i = 1; i < N; i++) {
		if (arr[i] > arr[max_i])
			max_i = i;
		if (arr[i] < arr[min_i])
			min_i = i;
	}
	if (max_i != 0) {
		tmp = arr[max_i];
		arr[max_i] = arr[0];
		arr[0] = tmp;	
	}
	if (min_i != 1) {
		tmp = arr[min_i];
		arr[min_i] = arr[1];	
		arr[1] = tmp;
	}

	// 遍历
	for (i = 0; i < N; i++) 
		printf("%d ", i[arr]); // *(arr+i)
	printf("\n");

	return 0;
}

