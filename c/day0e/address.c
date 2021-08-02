#include <stdio.h>

struct test_st {
	char ch;
	int i;
	short sh;
	int j;
};

/*
 如果已知结构体中某一个成员的地址，如何求得这个结构体的首地址
 */

int main(void)
{
	printf("%d\n", (int)&((struct test_st *)0)->i);

	return 0;
}

