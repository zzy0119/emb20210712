#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>


static int daemonInit(void);
int main(void)
{
	int err;

	if ((err = daemonInit()) < 0) {
		fprintf(stderr, "daemonInit():%s\n", strerror(-err));
		exit(1);
	}

	while (1) {
		system("ps aux > test.log");	
		printf("hello\n");
		sleep(3);
	}

	exit(0);
}

static int daemonInit(void)
{
	pid_t pid;
	int fd;
	struct rlimit rlimt;	

	umask(0);

	if (pid = fork()) {
		if (-1 == pid)
			return -errno;
		exit(0); // parent
	}
	if (setsid() == -1)
		return -errno;
	// PID == PGID == SID 
	chdir("/");

	fd = open("/dev/null", O_RDWR);
	if (fd == -1)
		return -errno;
	dup2(fd, 0);
//	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2)
		close(fd);

	// 关闭父进程没必要的文件
	getrlimit(RLIMIT_NOFILE, &rlimt);	
	for (int i = 3; i < rlimt.rlim_max; i++)
		close(i);

	return 0;
}



