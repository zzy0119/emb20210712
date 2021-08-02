/*
 大端存储：一个数值的低字节存在高地址，高字节存在低地址(arm)
 小端存储：一个数值的低字节存在低地址，高字节存储在高地址(pc)
 */
#include <stdio.h>

union {
	int num;
	char c;
}s;

int main(void)
{
	s.num = 0x12345678;
	if (s.c == 0x78) { // 低地址存放低字节
		printf("小端存储\n");
	} else if (s.c == 0x12) // 低地址存放高字节
		printf("大端存储\n");

	return 0;
}

