#include <stdio.h>

#define N	10

/*
 1
 1 1
 1 2 1
 1 3 3 1
 */

int main(void)
{
	int arr[N][N] = {};
	int i, j;

	for (i = 0; i < N; i++) {
		arr[i][0] = 1;
		for (j = 1; j < N; j++) {
			if (i == j) {
				arr[i][j] = 1;
			} else if (j < i && i > 0) // 左下角
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (j <= i)
				printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

