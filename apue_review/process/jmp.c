#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static jmp_buf env;

static int div2num(int m, int n)
{
	if (n == 0)
		longjmp(env, 1);

	return m / n;
}

int main(void)
{
	int n1, n2;	

	if (setjmp(env) == 0)
		printf("请输入两个整型变量的值:");
	else
		printf("请重新输入:");
	scanf("%d%d", &n1, &n2);
	printf("res: %d / %d = %d\n", n1, n2, div2num(n1, n2));

	exit(0);
}

