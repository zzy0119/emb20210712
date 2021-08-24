/*
 统计argv[1]文件所占用的磁盘空间大小
 du -sh 
 */

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATHSIZE 	128

int mydu(const char *path);
int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;
	printf("%d\n", mydu(argv[1]));

	return 0;
}

int mydu(const char *path)
{
	struct stat res;
	DIR *dp;
	struct dirent *entry;
	char paths[PATHSIZE] = {};
	int sum;

	puts(path);
	if (stat(path, &res) == -1) {
		perror("stat()");
		return -1;
	}
	if (!S_ISDIR(res.st_mode))
		return res.st_blocks / 2;

	// 目录自身大小
	sum = res.st_blocks / 2;

	// 累加目录下所有文件
	dp = opendir(path);
	if (NULL == dp)
		return -1;
	
	while (1) {
		errno = 0;
		entry = readdir(dp);	
		if (NULL == entry) {
			if (errno) {
				perror("readdir()");
				goto ERROR;
			}
			break;
		}
		if (strcmp(entry->d_name, ".") == 0 || \
				strcmp(entry->d_name, "..") == 0)
			continue;
		// path-->"/etc"
		memset(paths, '\0', PATHSIZE);
		strcpy(paths, path);
		strcat(paths, "/");
		strcat(paths, entry->d_name);
		// puts(paths);
		sum += mydu(paths);
	}

	closedir(dp);
	return sum;

ERROR:
	closedir(dp);
	return -1;
}


