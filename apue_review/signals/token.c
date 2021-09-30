#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

#define BUFSIZE	1024

struct token_st {
	int cps;
	int token;
	int burst;
};
static struct token_st tb;

static void alrmHandler(int s)
{
	alarm(1);
	tb.token += tb.cps;
	if (tb.token >= tb.burst)
		tb.token = tb.burst;
}

int main(int argc, char *argv[])
{
	struct sigaction act = {};
	int fd;
	char buf[BUFSIZE] = {};
	int cnt;

	if (argc < 3)
		exit(1);
	tb.cps = atoi(argv[2]);
	tb.token = 0;
	tb.burst = tb.cps * 50;

	act.sa_handler = alrmHandler;
	sigaction(SIGALRM, &act, NULL);
	alarm(1);	

	fd = open(argv[1], O_RDONLY);
	// if error

	while (1) {
		// 取令牌	
		while (tb.token < tb.cps)
			pause();
		tb.token -= tb.cps;

		cnt = read(fd, buf, tb.cps);
		if (cnt == -1) {
			perror("read()");
			close(fd);
			exit(1);
		}
		if (cnt == 0)
			break;
		write(1, buf, cnt);
	}

	close(fd);
}

