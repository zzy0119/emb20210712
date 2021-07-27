#include <stdio.h>

/*
 二维数组:
 	type arr[nmemb][n];
nmemb:有多少个一维数组
n:每个一维数组成员个数
 */

int main(void)
{
	int arr[2][3] = {{1,2,3},{7,8,9}};
	int i, j;	

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

