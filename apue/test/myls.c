#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

#define BUFSIZE		32
#define LISTSIZE	256
#define NAMESIZE	64

char typeFile(mode_t mode);
char *modeFile(mode_t mode);
long linkCnt(nlink_t link);
char *groupName(gid_t gid);
char *fileOwner(uid_t uid);
char *fileMTime(struct timespec mt);
long fileSize(off_t size);
long fileInode(ino_t ino);
int showLine(const char *path, int lflag, int iflag);

int main(int argc, char *argv[])
{
	showLine("./mygetline.c", 0, 0);

	return 0;
}

// 类型
char typeFile(mode_t mode)
{
	switch(mode & S_IFMT) {
		case S_IFSOCK:
			return 'a';
			break;
		case S_IFLNK:
			return 'l';
			break;
		case S_IFREG:
			return '-';
			break;
		case S_IFBLK:
			return 'b';
			break;
		case S_IFDIR:
			return 'd';
			break;
		case S_IFCHR:
			return 'c';
			break;
		case S_IFIFO: 
			return 'p';
			break;
		default:
			return '?';
			break;
	}
}

// 权限
char *modeFile(mode_t mode)
{
	int modes[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, \
	S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	int spc[3] = {S_ISUID, S_ISGID, S_ISVTX};
	char *spcChar = "sst";
	char *ret = malloc(10);
	// if error
	strcpy(ret, "rwxrwxrwx");
	for (int i = 0, j = 0; i < 9; i++) {
		if (!(modes[i] & mode))
			ret[i] = '-';
		else if (i % 3 == 2 && mode & modes[i]) {
			if (mode & spc[j])
				ret[i] = spcChar[j];
			j++;
		}
	}

	return ret;
}

// 硬连接个数
long linkCnt(nlink_t link)
{
	return link;
}

// 拥有者　
char *fileOwner(uid_t uid)
{
	struct passwd *pwd = getpwuid(uid);	
	if (NULL == pwd)
		return NULL;
	return pwd->pw_name;
}

// 所属组
char *groupName(gid_t gid)
{
	struct group *grp = getgrgid(gid);
	if (NULL == grp)
		return NULL;
	return grp->gr_name;
}

// 字节大小
long fileSize(off_t size)
{
	return size;
}

// mtime
char *fileMTime(struct timespec mt)
{
	static char buf[BUFSIZE] = {};
	struct tm *tmp = localtime(&mt.tv_sec);
	strftime(buf, BUFSIZE, "%m月%d %H:%M", tmp);

	return buf;
}

// 存储空间大小

// inode
long fileInode(ino_t ino)
{
	return ino;
}

int showLine(const char *path, int lflag, int iflag)
{
	struct stat res;
	char *r;
	char buf[LISTSIZE] = {};
	char name[NAMESIZE] = {};
	char tmp[BUFSIZE] = {};

	if (stat(path, &res) == -1) {
		perror("stat()");
		return -1;
	}
	r = strrchr(path, '/');
	if (r == NULL)
		strcpy(name, path);
	else
		strcpy(name, r+1);

	if (lflag == 0 && iflag == 0) {
		puts(name);
		return 0;
	}
	if (iflag) {
		snprintf(buf, LISTSIZE, "%ld ", res.st_ino);
	} 
	if (lflag) {
		snprintf(tmp, BUFSIZE, "%c", typeFile(res.st_mode));
		strcat(buf, tmp);
		strcat(buf, modeFile(res.st_mode));
		snprintf(tmp, BUFSIZE, " %ld ", linkCnt(res.st_nlink));
		strcat(buf, tmp);
		strcat(buf, fileOwner(res.st_uid));
		strcat(buf, " ");
		strcat(buf, groupName(res.st_gid));
		snprintf(tmp, BUFSIZE, " %ld ", fileSize(res.st_size));
		strcat(buf, tmp);
		strcat(buf, fileMTime(res.st_mtim));
		strcat(buf, " ");
	}

	strcat(buf, name);
	puts(buf);
}



