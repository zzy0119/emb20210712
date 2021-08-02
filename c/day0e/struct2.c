#include <stdio.h>

typedef struct color_st {
	int red;
	int green;
	int blue;
}c1;
// struct color_st c1;

int main(void)
{
	// c1结构体类型 test结构体类型的变量
	c1 test = {233, 167, 199};;

	printf("%d %d %d\n", test.red, test.green, test.blue);

	return 0;
}


