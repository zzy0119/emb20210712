#include <stdio.h>

int mystrlen(char *p);
char *mystrcpy(char *dest, char *src);
char *mystrcat(char *dest, char *src);
int mystrcmp(char *s1, char *s2);
int main(void)
{
	char str[100] = "hello world"; // 变量
	char *s = "nafternoon"; // 字符串常量，指针s存储首地址
	int ret;

	printf("%d\n", mystrlen(str));

//	mystrcpy(str, s);
	puts(str);

	ret = mystrcmp(str, s);
	if (ret == 0)
		printf("相等\n");
	else if (ret > 0)
		printf("第一个字符串大\n");
	else
		printf("第二个字符串大\n");

	return 0;
}

int mystrlen(char *p)
{
	int len = 0;

	while (*p++) {
		len++;
	}
	return len;	
}

char *mystrcpy(char *dest, char *src)
{
#if 0
	int i;		

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return dest;
#endif
	char *ret = dest;
	while (*dest++ = *src++) 
		;	
	return ret;
}

char *mystrcat(char *dest, char *src)
{
	char *ret;

	ret = dest;
	dest += mystrlen(dest);
	mystrcpy(dest, src);

	return ret;
}

int mystrcmp(char *s1, char *s2) 
{
	while (*s1 == *s2 && *s1) {
		s1++;
		s2++;
	}

	return *s1 - *s2;
}





