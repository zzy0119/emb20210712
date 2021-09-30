#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void sigHandler(int s)
{
	int i;
	for (i = 0; i < 3; i++) {
		write(1, "!", 1);
		sleep(1);
	}
}

int main(void)
{
	int i, j;	
	sigset_t set, oldset;

	signal(SIGINT, sigHandler);
	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_BLOCK, &set, &oldset);
	for (i = 0; i < 10; i ++) {
		for (j = 0; j < 5; j++) {
			write(1, "*", 1);
			sleep(1);
		}
		write(1, "\n", 1);
		sigsuspend(&oldset);
	}


	exit(0);
}

