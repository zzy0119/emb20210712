#include <stdio.h>

/*
 指针:存储地址的变量
 定义:type *name; type *变量的类型
 初始化:type *name = address;
 赋值:name = value;
 存储空间大小:64位-->指针都是8bytes
 			  32位-->指针都是4bytes
 指针的类型:
 	char * / int * / long *--->决定运算(++ -- * [] +/-)
	sizeof(char / int / long)
 指针的必要性:
 	通过形参(函数的参数)改变实参(调用者传递的参数)	
 
 */

void swap2num(int *a, int *b);
int main(void)
{
	int n = 257, m = 10;
	int *p = &n;
	char *q = &n;

	printf("%d\n", *p);
	printf("%d\n", p[0]);
	printf("%d\n", *q);

	swap2num(&n, &m);
	printf("m:%d, n:%d\n", m, n);

	return 0;
}

/*
 定义一个函数：交换两个整型变量
 */
void swap2num(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}






