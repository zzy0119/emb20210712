#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		exit(1);
	}
	if (0 == pid) {
		setpgid(0, getpid());
		printf("child pid:%d, pgid:%d, ppid:%d, sid:%d\n", \
				getpid(), getpgrp(), getppid(), getsid(0));
		exit(0);
	}
	wait(NULL);
	printf("parent pid:%d, pgid:%d, ppid:%d, sid:%d\n", \
			getpid(), getpgrp(), getppid(), getsid(0));

	exit(0);
}

