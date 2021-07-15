#include <stdio.h>

int main(void)
{
	int n;
	int res = 0;

	do {
		printf("请输入一个五位数:");
		scanf("%d", &n);
	} while (n < 10000 || n >= 100000);

	for (; n; n/=10) {
		res = res * 10 + n % 10;	
	}
	printf("逆数为%d\n", res);


	return 0;
}

