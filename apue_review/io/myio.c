#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE	10

int mycpy(int sfd, int dfd);
int mycat(const char *path);
int cpFile(const char *rpath, const char *wpath);
int main(int argc, char *argv[])
{
	if (argc < 3)
		return 1;
	mycat(argv[1]);

	cpFile(argv[1], argv[2]);

	return 0;	
}

int cpFile(const char *rpath, const char *wpath)
{
	int rfd = open(rpath, O_RDONLY);
	//if error
	int wfd = open(wpath, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	
	mycpy(rfd, wfd);

	return 0;
}

int mycpy(int sfd, int dfd)
{
	char buf[BUFSIZE] = {};
	int cnt;

	while (1) {
		memset(buf, '\0', BUFSIZE);	
		cnt = read(sfd, buf, BUFSIZE);
		if (cnt == -1) {
			perror("read()");
			return -1;
		}
		if (cnt == 0)
			break;
		write(dfd, buf, cnt);
	}

	return 0;
}

int mycat(const char *path)
{
	int fd;

	fd = open(path, O_RDONLY);	
	if (fd == -1) {
		perror("open()");
		return -1;
	}

	mycpy(fd, 1);

	close(fd);

	return 0;
}


