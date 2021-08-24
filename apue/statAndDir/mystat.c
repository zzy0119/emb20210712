#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define BUFSIZE	100

int main(int argc, char *argv[])
{
	struct stat res;

	if (argc < 2)	
		return 1;
	
	if (stat(argv[1], &res) == -1) {
		perror("stat()");
		return 1;
	}

	// 类型 -/d/l/c/b/d/s/p
	
	switch (res.st_mode & S_IFMT) {
		case S_IFREG:
			putchar('-');
			break;
		case S_IFDIR:
			putchar('d');
			break;
		case S_IFCHR:
			putchar('c');
			break;
		default:
			break;
	}

	// 文件权限
	if (res.st_mode & S_IRUSR)	
		putchar('r');
	else
		putchar('-');
	
	res.st_mode & S_IWUSR ? putchar('w') : putchar('-');
	if (res.st_mode & S_IXUSR) {
		if (res.st_mode & S_ISUID)
			putchar('s');
		else
			putchar('x');
	} else if (res.st_mode &S_ISUID)
		putchar('S');
	else
		putchar('-');

	// 硬链接个数
	printf(" %ld ",res.st_nlink);
		
	// 文件拥有者和所属组
	struct passwd *pwd = getpwuid(res.st_uid);
	if (NULL == pwd) {
		perror("getpwuid()");
		return 1;
	}
	struct group *grp = getgrgid(res.st_gid);
	if (NULL == grp) {
		perror("getgrgid()");
		return 1;
	}

	printf("%s %s", pwd->pw_name, grp->gr_name);

	// 文件字节大小 != 磁盘空间大小 st_blocks
	printf(" %ld ", res.st_size);

	// mtime
	char buf[BUFSIZE] = {};
	struct tm *tmp = localtime(&res.st_mtime);
	strftime(buf, BUFSIZE, "%m月 %d %H:%M", tmp);
	printf("%s ", buf);

	printf("%s", argv[1]);

	putchar('\n');

	return 0;
}

