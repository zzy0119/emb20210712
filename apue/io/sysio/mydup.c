#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;

	if (argc < 2)
		return 0;

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (-1 == fd) {
		perror("open()");
		return 1;
	}

	dup2(fd, 1);

	printf("hello world\n");

	close(fd);

	return 0;
}

