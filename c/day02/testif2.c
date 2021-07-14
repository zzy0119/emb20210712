#include <stdio.h>

/*
 读入一个三位的整型数,判断这个整型数是否满足既不是3的倍数也不是5的倍数
 */
int main(void)
{
	int num;

	printf("num:");
	scanf("%d", &num);

	if (num < 100 || num >= 1000) {
		printf("不符合三位数\n");
	} else {
		if (num % 3 && num % 5)
			printf("符合要求\n");
	}

	return 0;
}

