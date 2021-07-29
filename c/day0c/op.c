#include <stdio.h>

int main(void)
{
	char str[] = "worldhel";
	char *p = str;

	printf("%c\n", *p++); // char ch; ch = *p++;
	printf("%c\n", *(p++));
	printf("%c\n", (*p)++); // ch = (*p)++;
	printf("%c\n", ++*p);
	printf("%c\n", *++p);

	return 0;
}

