#include <stdio.h>
#include "mystring.h"

#define SIZE	100

int main(void)
{
	char str[SIZE] = "hello";
	const char *p = "world";

	str[0] = 'm';
	puts(str);
	// *p = 'z';

	printf("%d\n", mystrlen(str));
	mystrncpy(str, p, SIZE-1);
	puts(str);
	mystrcat(str, "catString");
	puts(str);
	p = mystrchr(str, 'a');
	if (p)
		puts(p);
	p = mystrstr(str, "cat");
	if (p)
		puts(p);

	return 0;
}

