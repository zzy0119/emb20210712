#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

void exitHandler1(int s, void *arg)
{
	fprintf(stdout, "%s is called\n", __FUNCTION__);
	free(arg);
}

void closeFile(int s, void *arg)
{
	fprintf(stdout, "%s is called\n", __FUNCTION__);
	fclose((FILE *)arg);
}

void testHandler(void)
{
	fprintf(stdout, "%s is called\n", __FUNCTION__);
}

int main(int argc, char *argv[]/*, char *environ[]*/)
{
	int i;
	char *p;
	FILE *fp;

	for (i = 0; environ[i]; i++)
		puts(environ[i]);

	p = calloc(100, 1);
	if (NULL == p)
		exit(1);

	on_exit(exitHandler1, p);

	fp = fopen("/etc/passwd", "r");
	if (fp == NULL) {
		exit(1);
	}

	on_exit(closeFile, fp);

	atexit(testHandler);

// 	_exit(0);
 	exit(0);
}

