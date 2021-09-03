#include <stdio.h>

#define SIZE	100

int main(void)
{
	char str[SIZE] = "hello";
	const char *p = "world";

	str[0] = 'm';
	puts(str);
	// *p = 'z';


	return 0;
}

