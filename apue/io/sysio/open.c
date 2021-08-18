#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE	10

int main(int argc, char *argv[])
{
	int fd;
	char buf[BUFSIZE] = {};
	int cnt;

	if (argc < 2)
		return 1;

	// mode & ~umask
	// fd = open(argv[1], O_RDONLY | O_CREAT | O_TRUNC, 0666);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		printf("open failed\n");
		return 1;
	}

	printf("fd:%d\n", fd);

	while (1) {
		cnt = read(fd, buf, BUFSIZE);	
		if (cnt == 0) {
			// eof
			break;
		} else if (cnt < 0) {
			// error
			printf("read() failed\n");
			goto ERROR;
		}
		write(1, buf, cnt);
	}

	close(fd);

	return 0;
ERROR:
	close(fd);
	return 1;
}

