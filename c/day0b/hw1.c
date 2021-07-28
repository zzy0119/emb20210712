#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define N	20
#define CNT	11

int main(void)
{
	int score[N];
	int grade[CNT] = {};
	int i;

	srand(getpid());
	for(i = 0; i < N; i++) {
		// printf("请输入第%d学生的成绩:", i+1);
		// scanf("%d", score+i); // &score[i]
		score[i] = rand() % 101;
		printf("%d ", score[i]);
		grade[score[i] / 10]++;
	}
	printf("\n");
	printf("100: ");
	for (i = 0; i < grade[CNT-1]; i++)
		printf("* ");
	printf("\n");
	for (i = 9; i >= 0; i--) {
		printf("%d~%d:", i*10, i*10+9);
		for (int j = 0; j < grade[i]; j++)
			printf("* ");
		printf("\n");
	}

	return 0;
}

