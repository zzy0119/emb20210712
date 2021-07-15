#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;

	i = 1; 
	while (i <= 100) {
		if (i % 2) {
			i++;
			continue; // 终止本次循环，继续下一次
		}
		if (i % 3 == 0 && i % 5 == 0)
			break; // 终止循环
		sum += i;
		i++;
	}

	/*
	for (i = 1; i <= 100; i++)
		sum += i;
		*/

	printf("sum:%d\n", sum);

	return 0;
}

