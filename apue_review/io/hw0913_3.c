#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <glob.h>

#define DEBUG
#undef	DEBUG

int mygetline(char **ptr, int fd);
int parseString(char *p, char *delim, glob_t *res);
int main(int argc, char **argv)
{
	char *p = NULL;
	int rfd, wfd;
	glob_t res;

	if (argc < 3)
		return 1;

	rfd = open(argv[1], O_RDONLY);
	if (rfd == -1) {
		perror("open()");	
		return 1;
	}
	wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	// if error

	while (1) {
		if (mygetline(&p, rfd) == 0)
			break;
		if (strcmp(p, "\n") == 0)
			continue;
		parseString(p, " \n", &res);
#ifdef DEBUG
		printf("[%d]debug\n", __LINE__);
#endif
		for (int i = 0; i < res.gl_pathc; i++) {
			write(wfd, *(res.gl_pathv+i), strlen((res.gl_pathv)[i]));
			write(wfd, "\n", 1);
		}
#ifdef DEBUG
		printf("[%d]debug\n", __LINE__);
#endif
		free(p);
		p = NULL;
		globfree(&res);
	}

	close(rfd);
	close(wfd);

	return 0;
}

int mygetline(char **ptr, int fd)
{
	char ch;
	int ret;
	int len = 1;

	*ptr = malloc(len); // '\0'

	while (1) {
		ret = read(fd, &ch, 1);
		if (ret == -1) {
			perror("read()");
			return -1;
		}
		if (ret == 0)
			break;
		*ptr = realloc(*ptr, (len+1) * sizeof(char));
		(*ptr)[len-1] = ch;
		len ++;
		if (ch == '\n')
			break;
	}
	(*ptr)[len-1] = '\0';
	if (ret == 0)
		return 0;
			
	return len;
}

int parseString(char *p, char *delim, glob_t *res)
{
	char *token;
	int i = 0;

	while (1) {
		token = strtok(p, delim);	
		if (token == NULL)
			break;
		glob(token, GLOB_NOCHECK | GLOB_APPEND * i, NULL, res);
		i = 1;
		p = NULL;
	}

	return 0;
}

