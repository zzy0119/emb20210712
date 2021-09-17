#include <stdio.h>
#include <string.h>
#include <glob.h>

#define PATHSIZE 128

static int parseDirGlob(const char *pattern, glob_t *res);
int main(int argc, char *argv[])
{
	glob_t g;

	if (argc < 2)
		return 1;

	parseDirGlob(argv[1], &g);

	for (int i = 0; i < g.gl_pathc; i++)
		puts((g.gl_pathv)[i]);

	globfree(&g);

	return 0;
}

static int parseDirGlob(const char *pattern, glob_t *res)
{
	char path[PATHSIZE] = {};
	char *p;

	if (glob(pattern, 0, NULL, res) != 0)
		return -1;
	// "/etc/*" -->"/etc/.*"
	p = strrchr(pattern, '/');
	if (NULL != p) {
		strncpy(path, pattern, p-pattern);
		strcat(path, "/.");
		strcat(path, p+1);
		glob(path, GLOB_APPEND, NULL, res);
	}

}

