#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(char *s, char *t, int i);
int main(int argc, char *argv[])
{
	char buf[1024] = {"hello world"};

	if (argc < 3)
		return 1;
	insert(buf, argv[1], atoi(argv[2]));
	puts(buf);


	return 0;
}

void insert(char *s, char *t, int i)
{
	int len = strlen(t);		

	memmove(s+i+len, s+i, strlen(s)-i);
	memcpy(s+i, t, len);
}



