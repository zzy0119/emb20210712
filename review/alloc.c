#include <stdio.h>

void getmemory(char **p)
{
	*p = malloc(100);
	strcpy(*p, "hello world");
}

int main(int argc, char *argv[])
{
	char *ptr;

	getmemory(&ptr);

	puts(ptr);

	free(ptr);

	return 0;
}

