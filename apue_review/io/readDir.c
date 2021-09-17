#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define BUFSIZE	128

static int parseDir(const char *path);
int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *entry;
	int err;

	if (argc < 2)
		return 1;

#if 0
	dp = opendir(argv[1]);
	if (NULL == dp) {
		perror("opendir()");
		return 1;
	}

	while (1) {
		entry = readdir(dp);
		if (NULL == entry) {
			if (errno) {
				perror("readdir()");
				goto ERROR;
			}
			break;
		}
		puts(entry->d_name);
	}

	closedir(dp);
#endif
	if ((err = parseDir(argv[1])) < 0) {
		fprintf(stderr, "parseDir():%s\n", strerror(-err));
		return 1;
	}

	return 0;
ERROR:
	closedir(dp);
	return 1;
}

static int parseDir(const char *path)
{
	struct stat res;
	DIR *dp;
	struct dirent *entry;
	char buf[BUFSIZE] = {};

	if (stat(path, &res) == -1) {
		perror("stat()");
		return -1;
	}
	if (!S_ISDIR(res.st_mode)) {
		puts(path);
		return 0;
	}

	puts(path);

	dp = opendir(path);
	if (NULL == dp) {
		return -errno;
	}

	while (1) {
		entry = readdir(dp);
		if (NULL == entry) {
			if (errno) {
				closedir(dp);
				return -errno;
			}
			break;
		}
		if (strcmp(entry->d_name, ".") == 0 || \
				strcmp(entry->d_name, "..") == 0)
			continue;
		memset(buf, '\0', BUFSIZE);
		strcpy(buf, path);
		strcat(buf, "/");
		strcat(buf, entry->d_name); // "path/xxx"
		parseDir(buf);
	}	
	closedir(dp);	

	return 0;
}







