#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define BUFSIZE	128	

static const char *fileTime(struct timespec mtime, const char *format)
{
	static char buf[BUFSIZE] = {};

	struct tm *tmp = localtime(&mtime.tv_sec);
	if (NULL == tmp)
		return NULL;
	strftime(buf, BUFSIZE, format, tmp);

	return buf;
}

static int fileBlocks(blkcnt_t blk)
{
	return blk / 2;
}

static int fileSize(off_t size)
{
	return size;
}

static const char *fileGroup(gid_t gid)
{
	struct group *grp = getgrgid(gid);
	if (NULL == grp)
		return NULL;
	return grp->gr_name;
}

static const char *fileOwner(uid_t uid)
{
	struct passwd *pwd = getpwuid(uid);
	if (NULL == pwd)
		return NULL;
	return pwd->pw_name;
}

static int fileNlink(nlink_t n)
{
	return n;
}

static char fileType(mode_t mode)
{
	char ret;
	switch (mode & S_IFMT) {
		case S_IFREG:
			ret = '-';
			break;
		case S_IFDIR:
			ret = 'd';
			break;
		default:
			ret = '?';
			break;
	}
	return ret;
}

static char *fileMode(mode_t mode)
{
	char *ret;
	int modes[] = {S_IRUSR, S_IWUSR, S_IXUSR, \
	S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	int i;

	ret = malloc(10);
	if (NULL == ret)
		return NULL;

	strcpy(ret, "rwxrwxrwx");

	for (i = 0; i < sizeof(modes) / sizeof(modes[0]); i++) {
		if (!(modes[i] & mode))
			ret[i] = '-';
	}

	return ret;
}

int main(int argc, char *argv[])
{
	struct stat res;
	if (argc < 2)
		return 1;

	if (stat(argv[1], &res) == -1) {
		perror("stat()");
		return 1;
	}

	printf("%c%s %d %s %s %d %s\n", fileType(res.st_mode), fileMode(res.st_mode), fileNlink(res.st_nlink), fileOwner(res.st_uid), \
			fileGroup(res.st_gid), fileSize(res.st_size),\
			fileTime(res.st_mtim, "%m月 %d %H:%M"));

	return 0;
}

