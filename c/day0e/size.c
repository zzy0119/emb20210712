#include <stdio.h>

/*
 相邻元素对齐，整体最大成员(字节)的倍数
 */

// 指定结构体的对齐规则
// #pragma pack(1) // 2^n 并且不能超过最大

struct test_st {
	char ch;
	short sh;
	int in;
	char ch2;
	char ch3;
	short sh2;
}__attribute__((packed)); // 等效于2^0
 
int main(void)
{
	struct test_st t;

	printf("%ld\n", sizeof(t));


	return 0;
}

