#include <stdio.h>

/*
 运算符: man 5 operator
 单目运算符:
 	() [] * & ~ ! ++ -- -/+ sizeof . -> (type)
 算术运算符:
 	+ - * / %
 关系运算符:
 	> >= < <= != == 
 位运算符:
 	>> << & | ^ ~
 逻辑运算符
 	&& || !
 条件运算符:
 	?:
 赋值运算符
 	= += -= *= /= &= |= ^= %= >>= <<=
 逗号运算符:
 	,
 */

int main(void)
{
	int m, n;
	int res;

	m = 10;
	n = 20;

	res = m % n;
	printf("%d\n", res);

	res = m & n;	
	printf("%d\n", res);
	res = m | n;	
	printf("%d\n", res);
	res = m ^ n;	
	printf("%d\n", res);
	res = ~m;
	printf("%d\n", res);
	
	res = m >> 2;
	printf("%d\n", res);
	res = m << 2;
	printf("%d\n", res);

	// 将一个整型变量的第3位置为1
	m = m | (1 << 2);
	printf("%#x\n", m); // 十六进制

	// 将一个整型变量的第5位清为0
	m = 62;
	m = m & ~(1 << 4);
	printf("%#x\n", m);

	m = 30;

	printf("%d\n", !(m > 100) && n < 50);
	printf("%d\n", m > 100 || n < 50);

	m += 1; // m = m + 1;
	m ++;

	return 0;
}

