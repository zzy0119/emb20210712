#include <stdio.h>

#define BUFSIZE	100

int mycopy(FILE *rfd, FILE *wfd);
int main(int argc, char *argv[])
{
	if (argc < 3)
		return 1;
	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "w");

	mycopy(fp1, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}

int mycopy(FILE *rfd, FILE *wfd)
{
	int ch;
	char buf[BUFSIZE] = {};

	while (1) {
#if 0
		ch = fgetc(rfd);	
		if (ch == EOF) {
			if (ferror(rfd))
				return -1;
			break;
		}
		fputc(ch, wfd);
#endif
		if (fgets(buf, BUFSIZE, rfd) == NULL) {
			if (ferror(rfd))
				return -1;
			break;
		}
		fputs(buf, wfd);
	}

	return 0;
}


