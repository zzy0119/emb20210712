#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <syslog.h>

#define LOCKFILE	"/var/run/mydaemon.pid"
#define BUFSIZE		32

static int daemonInit(void);
static int runningAlready(void);
int main(void)
{
	int err;

	// 创建连接
	openlog("mydaemon", LOG_PID, LOG_DAEMON);

	if ((err = daemonInit()) < 0) {
	//	fprintf(stderr, "daemonInit():%s\n", strerror(-err));
		syslog(LOG_ERR, "daemonInit():%s", strerror(-err));
		exit(1);
	}

	if ((err = runningAlready()) == -1) {
		syslog(LOG_ERR, "runningAlready():%s", \
				strerror(-err));	
		exit(1);
	}

	while (1) {
		system("ps aux > test.log");
		syslog(LOG_INFO, "test succesfully");
		sleep(3);
	}

	closelog();

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
	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2)
		close(fd);

	// 关闭父进程没必要的文件
	getrlimit(RLIMIT_NOFILE, &rlimt);	
	for (int i = 3; i < rlimt.rlim_max; i++)
		close(i);

	return 0;
}
// 单实例守护进程
static int runningAlready(void)
{
	int fd;	
	char buf[BUFSIZE] = {};

	fd = open(LOCKFILE, O_WRONLY | O_CREAT, 0666);
	ckf(fd, F_TLOCK, 0) == -1) (lockf(fd, F_TLOCK, 0) == -1) (lockf(fd, F_TLOCK, 0) == -1) (lockf(fd, F_TLOCK, 0) == -1) 
	if (-1 == fd) {
		syslog(LOG_ERR, "open():%s", strerror(errno));
		return -1;
	}
	if (lockf(fd, F_TLOCK, 0) == -1) {
		if (errno == EACCES || errno == EAGAIN)	{
			// 被占用
			close(fd);		
			return -1;
		}
		syslog(LOG_ERR, "lockf():%s", strerror(errno));
		return -1;
	}
	// 第一次运行
	ftruncate(fd, 0);	
	snprintf(buf, BUFSIZE, "%d", getpid());
	write(fd, buf, strlen(buf)+1);
	
	return 0;
}



