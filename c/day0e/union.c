#include <stdio.h>

union number_un{
	int num;
	char c;
};

int main(void)
{
	union number_un u;
	u.num = 511;// (256+255)
	/*
	 1(符号位)111 1111
	 -1
	 */

	printf("%d\n", u.c);

	printf("%ld\n", sizeof(u));

	return 0;
}

