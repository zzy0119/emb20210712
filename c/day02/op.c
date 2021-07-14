#include <stdio.h>

int main(void)
{
	int m, n;
	int r;
/*
	printf("请输入一个整型:");
	scanf("%d", &m);

	m % 2 == 0 ? printf("偶数") : printf("奇数");
	// 读入俩个整型变量，输出较大的
	printf("请输入两个整型变量:");
	scanf("%d%d", &m, &n);

	printf("%d\n", m > n ? m : n);
*/

	// 自增自减运算符
	m = 10;
	n = m++;
	printf("m:%d, n:%d\n", m , n);
	n = ++m;
	printf("m:%d, n:%d\n", m , n);

	m = 5, n = 10;
	r = m+++n; // 贪婪规则
	printf("m:%d, n:%d, r:%d\n", m, n, r);

	m = 5, n = 10;
	r = (m++, n--, m+n);
	printf("m:%d, n:%d, r:%d\n", m, n, r);

	// 强制转换-->同类型才能运算
	m = 1.9; // 隐式强转
	printf("%d\n", m);
	n = (int)10.87; // 显式强转
	printf("%d\n", n);
	char ch = 'a';
	m = 10;
	n = m + (int)ch;
	printf("n:%d\n", n);

	// sizeof
	printf("%ld\n", sizeof(m));
	printf("%ld\n", sizeof(int));
	printf("%ld\n", sizeof m);


	return 0;
}

