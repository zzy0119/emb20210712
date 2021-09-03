#include <stdio.h>

int mystrlen(const char *ptr)
{
	int len = 0;

	while (*ptr++) {
		len++;
	}

	return len;
}

char *mystrncpy(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i]; i++) {
		dest[i] = src[i];
	}
	for (; i < n; i++)
		dest[i] = '\0';

	return dest;
}

char *mystrcat(char *dest, const char *src)
{
	char *ret = dest;

	while (*dest)
		dest ++;
	while ((*dest = *src) != '\0') {
		dest++;
		src++;
	}

	return ret;
}

int mystrcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2) {
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}

	return *s1 - *s2;
}

char *mystrchr(const char *ptr, char ch)
{
	int i;

	for(i = 0; ptr[i]; i++)
		if (ptr[i] == ch)
			return (char *)(ptr+i);
	return NULL;
}

// "hello eeeveryone" "every"
char *mystrstr(const char *longstr, const char *substr)
{
	int i;
	const char *startLong, *startSub;

	for (i = 0; longstr[i]; i++) {
		if (longstr[i] == *substr) {
			startLong = longstr+i+1;
			startSub = substr+1;	
			while (*startLong == *startSub && *startSub) {
				startLong++;
				startSub++;	
			}
			if (*startSub == '\0')
				return (char *)longstr+i;
		}
	}
	return NULL;
}






