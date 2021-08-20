#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE	20

int cpFile(FILE *src, FILE *dest, int line);

int main(int argc, char *argv[])
{
	FILE *fp, *tmpFp;
	int n;

	if (argc < 4)
		return 1;

	fp = fopen(argv[1], "r+");
	// if error;
	tmpFp = tmpfile();
	// if error;

	n = atoi(argv[2]);

	// fp文件的前n-1行写入临时文件
	cpFile(fp, tmpFp, n-1);

	// argv[3]字符串写入临时文件
	fputs(argv[3], tmpFp);

	// fp余下内容写入临时文件
	cpFile(fp, tmpFp, -1);

	// 临时文件写回来
	rewind(fp);
	rewind(tmpFp);
	cpFile(tmpFp, fp, -1);

	fclose(fp);
	fclose(tmpFp);

	return 0;
}


// line == -1写全部
int cpFile(FILE *src, FILE *dest, int line)
{
	char buf[BUFSIZE] = {};
	int len;

	while (line != 0) {
		memset(buf, '\0', BUFSIZE);
		if (fgets(buf, BUFSIZE, src) == NULL) {
			if (ferror(src))
				goto ERROR;
			break;
		}
		// strchr(buf, '\n')			
		if (buf[strlen(buf)-1] == '\n')
			line--;
		fputs(buf, dest);		
	}

ERROR:
	return -1;
}




