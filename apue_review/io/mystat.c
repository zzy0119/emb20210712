#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define BUFSIZE		128	
#define OPTSTRING	"-lah"

#define F_ISL		0001 // -l
#define F_ISA		0002 // -a
#define F_ISH		0004
#define F_NONOPT	0010 // 000 001 000

typedef short opt_t;
static int nonoptInd;

// static opt_t mode;

static void setBit(opt_t *opt, int n)
{
	*opt = *opt | 1u << n;
}

static int parseOpt(int argc, char *argv[], opt_t *opt)
{
	int c;

	while (1) {
		c = getopt(argc, argv, OPTSTRING);
		if (c == -1)
			break;
		switch (c) {
			case 'a':
				setBit(opt, 1);
				break;
			case 'l':
				setBit(opt, 0);
				break;
			case 'h':
				setBit(opt, 2);
				break;
			case 1:
				setBit(opt, 3);
				nonoptInd = optind - 1;
				break;
			default:
				break;
		}
	}
}

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
	opt_t mode = 0;

	parseOpt(argc, argv, &mode);

	if (mode & F_NONOPT) {
		if (stat(argv[nonoptInd], &res) == -1) {
			perror("stat()");
			return 1;
		}

#if 0
		printf("%c%s %d %s %s %d %s\n", fileType(res.st_mode), fileMode(res.st_mode), fileNlink(res.st_nlink), fileOwner(res.st_uid), \
				fileGroup(res.st_gid), fileSize(res.st_size),\
				fileTime(res.st_mtim, "%m月 %d %H:%M"));
#endif

		if (mode & F_ISL) {
			printf("%c%s %d %s %s %d %s ", fileType(res.st_mode),\
					fileMode(res.st_mode), fileNlink(res.st_nlink), \
					fileOwner(res.st_uid), \
					fileGroup(res.st_gid), fileSize(res.st_size),\
					fileTime(res.st_mtim, "%m月 %d %H:%M"));

		} 
		if (mode & F_ISA){
			// 
		} 
		if (mode & F_ISH) {
			printf("%dk ", fileBlocks(res.st_blocks));	
		}
		printf("%s ", argv[nonoptInd]);
		printf("\n");
	}

	return 0;
}

