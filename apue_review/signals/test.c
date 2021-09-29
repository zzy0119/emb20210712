#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static void sig_handler1(int s)
{
	printf("pid:%d\n", getpid());
	write(1, "child end", 9);
}

static void sig_handler2(int s)
{
	write(1, "!", 1);
}

int main(void)
{
	pid_t pid;

	signal(SIGCHLD, sig_handler1);
	signal(SIGINT, sig_handler2);

	pid = fork();
	// if error
	if (0 == pid) {
		printf("child pid:%d\n", getpid());
		write(1, "hello\n", 6);
		sleep(100);
		exit(0);
	}
	// wait(NULL);
	pause();

	exit(0);
}

