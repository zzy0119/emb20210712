#include <stdio.h>

int main(void)
{
	int n;
	int prev1, prev2;
	int res;

	printf("输入要求的第几项:");
	scanf("%d", &n);

	prev1 = prev2 = 1;
	res = 1;

	if (n > 2) {
		while (n > 2) {
			res = prev1 + prev2;
			prev2 = prev1;
			prev1 = res;
			n --;
		}
	}
	printf("res:%d\n", res);

	return 0;
}

