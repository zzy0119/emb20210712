#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void sigHandler(int s)
{
	for (int i = 0; i < 3; i++) {
		write(1, "!", 1);
		sleep(1);
	}
}

int main(void)
{
	signal(SIGINT, sigHandler);

	while (1) {
		write(1, "*", 1);
		sleep(1);	
	}

	exit(0);
}

