/*
子进程将argv[1]文件写入argv[2],
父进程等待子进程写完后，将argv[2]文件写到终端 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE	128

static int cpFile(int rfd, int wfd);
int main(int argc, char *argv[])
{
	int rfd;
   	int wfd;
	pid_t pid;

	if (argc < 3)
		exit(1);


	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		goto FORKERROR;
	}
	if (0 == pid) {
		rfd = open(argv[1], O_RDONLY);
		// if error
		wfd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
		// if error
		cpFile(rfd, wfd);
		close(rfd);
		close(wfd);
		exit(0);
	}
	wait(NULL);
	rfd = open(argv[2], O_RDONLY);
	if (-1 == rfd) {
		perror("open()");
		exit(1);
	}
	cpFile(rfd, 1);
	close(rfd);
	
	exit(0);
FORKERROR:
	close(rfd);
	exit(1);
}

static int cpFile(int rfd, int wfd)
{
	char buf[BUFSIZE] = {};
	int cnt;
	
	while (1) {
		cnt = read(rfd, buf, BUFSIZE);
		if (cnt == 0) 
			break;
		if (cnt == -1) {
			return -errno;
		}
		write(wfd, buf, cnt);
	}

	return 0;
}

