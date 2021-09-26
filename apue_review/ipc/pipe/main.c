#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFSIZE	128

static int mycp(int rfd, int wfd);
int main(int argc, char *argv[])
{
	int pfd[2] = {};
	pid_t pid;
	int fd;

	if (argc < 2)
		exit(1);
	if (pipe(pfd) == -1) {
		perror("pipe()");
		exit(1);
	}
	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		goto ERROR;
	}
	if (0 == pid) {
		close(pfd[1]);
		mycp(pfd[0], 1);
		close(pfd[0]);
		exit(0);
	}
	close(pfd[0]);
	// 打开argv[1]
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd) {
		close(pfd[1]);	
		perror("open()");
		exit(1);
	}
	mycp(fd, pfd[1]);
	close(pfd[1]);
	wait(NULL);
	
	return 0;
ERROR:
	close(pfd[0]);
	close(pfd[1]);
	exit(1);
}

static int mycp(int rfd, int wfd)
{
	char buf[BUFSIZE] = {};
	int cnt;
	
	while (1) {
		cnt = read(rfd, buf, BUFSIZE);
		if (-1 == cnt) {
			return -errno;
		}
		if (0 == cnt)
			break;
		write(wfd, buf, cnt);	
	}
}

