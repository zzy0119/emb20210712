#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

static int isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

char *test(const char *p)
{
	char *ret;	
	int i;

	ret = malloc(strlen(p)+1);
	// ret = calloc(strlen(p)+1, sizeof(char));
	if (NULL == ret)
		return NULL; // NULL--->(void *)0
	// 初始化存储空间
	// memset(ret, 0, strlen(p)+1);
	bzero(ret, strlen(p)+1);
	for (i = 0; p[i]; i++) {
		if (isUpper(p[i])) {
			ret[i] = p[i]+('a'-'A');
		} else if (isLower(p[i]))
			ret[i] = p[i]-('a'-'A');
		else
			ret[i] = p[i];
	}
	ret[i] = '\0';

	return ret;
}

int main(void)
{
	char *p = "hello WORLD123";
	char *r;

	r = test(p);
	puts(r);

	free(r);

	return 0;
}

