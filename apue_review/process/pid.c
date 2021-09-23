#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int n = 10;

	printf("pid:%d, ppid:%d\n", getpid(), \
			getppid());
	printf("this is the parent's buffer");
	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		exit(1);
	}
	if (pid == 0) {
		 // child	
		// sleep(1);
		printf("[child process]pid:%d, ppid:%d\n", getpid(), \
			getppid());
		printf("n:%d\n", n);
		n = 20;
		exit(0);
	}

	// sleep(1);
	// wait(NULL);
	waitpid(-1, NULL, 0);
	printf("parent n:%d\n", n);
	printf("byebye\n");

	exit(0);
}

