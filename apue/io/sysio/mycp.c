/*
 argv[1]文件复制到argv[2]
 */
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE	32

int main(int argc, char *argv[])
{
	int rfd, wfd;
	char buf[BUFSIZE] = {};
	int cnt;

	if (argc < 3)
		return 1;

	rfd = open(argv[1], O_RDONLY);
	if (-1 == rfd) {
		// printf("open() failed\n");
		// printf("open():%s\n", strerror(errno));
		perror("open()");
		return 1;
	}
	wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (-1 == wfd) {
		close(rfd);
		printf("open() failed\n");
		return 1;
	}

	while (1) {
		cnt = read(rfd, buf, BUFSIZE);
		if (cnt == -1) {
			printf("read() failed\n");
			goto ERROR;
		}
		if (cnt == 0)
			break;
		write(wfd, buf, cnt);
	}

	close(rfd);
	close(wfd);

	return 0;
ERROR:
	close(rfd);
	close(wfd);
	return 1;
}

