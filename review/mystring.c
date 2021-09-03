
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





