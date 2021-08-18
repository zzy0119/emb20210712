#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE	100

int main(int argc, char *argv[])
{
	int fd;
	int curSet;
	char buf[BUFSIZE] = {};

	if (argc < 2)
		return 1;

	fd = open(argv[1], O_RDONLY);
	if (-1 == fd) {
		perror("open()");
		return 1;
	}

	curSet = lseek(fd, -10, SEEK_END);
	if (-1 == curSet) {
		perror("lseek()");
		close(fd);
		return 1;
	}

	printf("%d\n", curSet);
	read(fd, buf, BUFSIZE);

	puts(buf);

	close(fd);

	return 0;
}

