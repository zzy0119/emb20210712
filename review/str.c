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

int mystrlen(const char *ptr)
{


}

char *mystrncpy(char *dest, const char *src, int n)
{


}

char *mystrcat(char *dest, const char *src)
{

}

int mystrcmp(const char *s1, const char *s2)
{

}

char *mystrchr(const char *ptr, char ch)
{

}

// "hello everyone" "every"
char *mystrstr(const char *longstr, const char *substr)
{

}





