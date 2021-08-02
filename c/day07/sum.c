#include <stdio.h>

/*
 递归函数:
 	在函数内部调用自身函数
 条件:
 	递归点
	终止条件
 */

int f(int n);
int fib(int n);
int main(void)
{
	for (int i = 1; i < 10; i++) {
		printf("%d\n", f(i));
	}

	for (int i = 1; i <= 20; i++)
		printf("%d ", fib(i));
	printf("\n");

	return 0;
}

/*
计算一个整型变量的前n项和 
int f(n);
n的前n项和==n+n-1的前n项和
 */
int f(int n)
{
	if (n == 0)
		return 0;
	return n + f(n-1);
}

/*
斐波那契数列的第ｎ项
1 1 2 3 5 8 13 21 ......
 */
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fib(n-1) + fib(n-2);
}




