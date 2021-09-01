#include <stdio.h>

#define BUFSIZE	128

char *mystrcpy(char *dest, const char *src);
int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;

	char buf[BUFSIZE] = {};

	mystrcpy(buf, argv[1]);
		
	puts(buf);
	
	return 0;
}

char *mystrcpy(char *dest, const char *src)
{
	int i;

#if 0
	for (i = 0; src[i]; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
#endif

	i = 0;
	while ((dest[i] = src[i]) != '\0')
		i++;

	return dest;	
}

