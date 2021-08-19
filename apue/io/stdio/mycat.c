#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE	100

int main(int argc, char *argv[])
{
	// stdin 0  stdout 1 stderr 2
	FILE *fp;
	int ch;
	char buf[BUFSIZE] = {};
	int cnt;

	if (argc < 2)
		return 1;

	fp = fopen(argv[1], "r");
	if (NULL == fp) {
		perror("fopen()");
		return 1;
	}

	while (1) {
#if 0
		ch = fgetc(fp);
		if (ch == EOF) {
			if (ferror(fp)) {
				printf("fgetc() failed\n");
				goto ERROR;
			} else
				break;
		}
		fputc(ch, stdout);
		fflush(NULL);
		sleep(1);
#endif
#if 0
		// 按行
		memset(buf, '\0', BUFSIZE);
		if (fgets(buf, BUFSIZE, fp) == NULL) {
			if (ferror(fp))
				goto ERROR;
			else
				break;
		}
		fputs(buf, stdout);
#endif
		// 二进制读写
		cnt = fread(buf, 1, BUFSIZE, fp);
		if (cnt == 0) {
			if (ferror(fp))
				goto ERROR;
			break;
		}
		fwrite(buf, 1, cnt, stdout);
	}

	fclose(fp);

	return 0;
ERROR:
	fclose(fp);
	return 1;
}

