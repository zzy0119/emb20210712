#include <stdio.h>

#define BUFSIZE	100

int reverseFile(const char *path);
static int cpfile(FILE *srcFp, FILE *destFp);

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
		return 1;

	reverseFile(argv[1]);
	fp = fopen(argv[1], "r");

	cpfile(fp, stdout);

	fclose(fp);

	return 0;
}

static int cpfile(FILE *srcFp, FILE *destFp)
{
	char buf[BUFSIZE] = {};		
	int cnt;

	while (1) {
		if ((cnt = fread(buf, 1, BUFSIZE, srcFp)) == 0) {
			if (ferror(srcFp))
				return -1;
			break;
		}
		fwrite(buf, 1, cnt, destFp);
	}

	return 0;
}

int reverseFile(const char *path)
{
	FILE *fp;
	FILE *tmp;
	int len;
	int ch;

	fp = fopen(path, "r+");
	if (NULL == fp)
		return -1;
	tmp = tmpfile();
	if (NULL == fp)
		return -1;

	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	
	while (--len >= 0) {
		fseek(fp, len, SEEK_SET);
		ch = fgetc(fp);
		fputc(ch, tmp);
	}
	rewind(fp);
	rewind(tmp);

	cpfile(tmp, fp);

	fclose(fp);
	fclose(tmp);

	return 0;
}




