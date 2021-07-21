#include <stdio.h>

#include "./op.h"

// 外部声明全局变量t1
extern int t1;
// extern int t2; 不可以

int main(void)
{
	int m, n;
	int res;

	printf("t1:%d\n", t1);
	// printf("t2:%d\n", t2); // 不可以

	scanf("%d%d", &m, &n);

	res = add2num(m, n);
	printf("%d + %d = %d\n", m, n, res);

	return 0;
}

