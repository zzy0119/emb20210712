#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
 产生随机数
 	rand(3)
	srand(3)
	getpid(2)
 */

int main(void)
{
	int i;
	int n;

	// scanf("%d", &n);
	n = getpid(); // 进程号

	// 设定随机数种子
	srand(n);
	for (i = 0; i < 10; i++)
		printf("%d\n", rand() % 100);

	return 0;
}

