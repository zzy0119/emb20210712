#include <stdio.h>

int isFlower(int n);
int main(void)
{
	int i;

	for (i = 100; i < 1000; i++)
		if (isFlower(i))
			printf("%d\n", i);

	return 0;
}

// 判断给定的整型数是否为水仙花数
int isFlower(int n)
{
	int save;
	int sum = 0;
	int t;

	if (!(n >= 100 && n < 1000))
		return 0;
	save = n;
	while (n) {
		t = n % 10;
		sum += t * t * t;
		n /= 10;	
	}
		
	return save == sum;
}

