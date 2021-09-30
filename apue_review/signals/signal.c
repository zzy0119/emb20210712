#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void sigHandler(int s)
{
	alarm(5);
	for (int i = 0; i < 3; i++) {
		write(1, "!", 1);
		sleep(1);
	}
}

int main(void)
{
	struct sigaction act = {};
   	struct sigaction oldact;
	// signal(SIGINT, sigHandler);

#if 0
	act.sa_handler = sigHandler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	sigaction(SIGINT, &act, &oldact);
#endif

	act.sa_handler = sigHandler;
	sigemptyset(&act.sa_mask);	
	sigaddset(&act.sa_mask, SIGINT);
	sigaddset(&act.sa_mask, SIGQUIT);
	sigaction(SIGALRM, &act, NULL);

	alarm(5);

	while (1) {
		write(1, "*", 1);
		sleep(1);	
	}

	exit(0);
}

