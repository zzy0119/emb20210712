#include <stdio.h>

#define N	10

int yh(int (*p)[N], int n);
int main(void)
{
	int a[N][N] = {};
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	int i, j;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", arr[i][j]);
	}
	printf("\n");

	yh(a, N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (j <= i)
				printf("%3d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int yh(int (*p)[N], int n)
{
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (j == 0 || i == j)
				p[i][j] = 1;
			else if (i > 0) {
				p[i][j] = p[i-1][j] + p[i-1][j-1];
			}
		}
	}
}









