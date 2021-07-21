#include <stdio.h>

void showImg2(int line);
void showImg(int line);
int main(void)
{
	showImg(10);
	showImg2(10);

	return 0;
}

void showImg(int line)
{
	int i, j;

	for (i = 0; i < line; i++) {
		for (j = 0; j <= i; j++)
			printf("* ");
		printf("\n");
	}
}

void showImg2(int line)
{
	int i, j;

	for (i = 0; i < line; i++) {
		// ' '
		for (j = 0; j < line-i-1; j++)
			printf("  ");
		// '*'
		for (j = 0; j < 2*i+1; j++)
			printf("* ");
		printf("\n");
	}
}










