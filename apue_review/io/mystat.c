#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static char fileType(mode_t mode)
{
	char ret;
	switch (mode & S_IFMT) {
		case S_IFREG:
			ret = '-';
			break;
		case S_IFDIR:
			ret = 'd';
			break;
		default:
			ret = '?';
			break;
	}
	return ret;
}

static char *fileMode(mode_t mode)
{
	char *ret;
	int modes[] = {S_IRUSR, S_IWUSR, S_IXUSR, \
	S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	int i;

	ret = malloc(10);
	if (NULL == ret)
		return NULL;

	strcpy(ret, "rwxrwxrwx");

	for (i = 0; i < sizeof(modes) / sizeof(modes[0]); i++) {
		if (!(modes[i] & mode))
			ret[i] = '-';
	}

	return ret;
}

int main(int argc, char *argv[])
{
	struct stat res;
	if (argc < 2)
		return 1;

	if (stat(argv[1], &res) == -1) {
		perror("stat()");
		return 1;
	}

	printf("%c%s\n", fileType(res.st_mode), fileMode(res.st_mode));

	return 0;
}

