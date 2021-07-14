#include <stdio.h>

int main(void)
{
	int a, b;
	a = 2, b = 3;

	printf("%f\n", (float)(a+b) / 2);

	a = 12;
	a = a++*1/3;
	printf("%d\n", a);

	return 0;
}

