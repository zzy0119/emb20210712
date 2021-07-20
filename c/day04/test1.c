#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int i, n;

	srand(getpid());	

	for (i = 0; i < 100; ) {
		n = rand() % 1000;	
		if (n < 100)
			continue;
		// 一定是一个随机的三位数
		if (n % 3 == 0 && n % 5 == 0 && n % 7 == 0)	
			printf("%d满足条件\n", n);
		i++;
	}

	return 0;
}

