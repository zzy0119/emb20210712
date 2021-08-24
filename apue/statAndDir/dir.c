#include <stdio.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *entry;

	if (argc < 2)
		return 1;

	dp = opendir(argv[1]);
	if (NULL == dp) {
		perror("opendir()");
		return 1;
	}

	while (1) {
		entry = readdir(dp);	
		if (NULL == entry) {
			if (!errno)
				break;
			perror("readdir()");
			goto ERROR;
		}
		printf("%s\n", entry->d_name);
	}

	closedir(dp);
	return 0;
ERROR:
	closedir(dp);
	return 1;
}

