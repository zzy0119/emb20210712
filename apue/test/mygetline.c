#include <stdio.h>
#include <stdlib.h>

#define ALLOCSIZE 10	

ssize_t mygetline(char **lineptr, size_t *n, FILE *fp);
int main(int argc, char *argv[])
{
	char *ptr = NULL;
	size_t n = 0;

	while (1) {
		if (mygetline(&ptr, &n, stdin) == -1)
			break;
		puts(ptr);
		free(ptr);
		ptr = NULL;
		n = 0;
	}

	return 0;
}

ssize_t mygetline(char **lineptr, size_t *n, FILE *fp)
{
	int c;
	int i = 0;

	if (*lineptr == NULL && *n == 0) {
		*lineptr = calloc(ALLOCSIZE, sizeof(char));
		*n = ALLOCSIZE;
	}

	while (1) {
		// 有空间
		if (i > *n-2) {
			*n += ALLOCSIZE;
			*lineptr = realloc(*lineptr, *n);
			// if error
		}
		c = fgetc(fp);
		if (c == EOF) {
			if (ferror(fp)) {
				fprintf(stderr, "fgetc() failed\n");
				return -1;
			}
			(*lineptr)[i] = '\0';
			return -1;
		}
		(*lineptr)[i++] = c;
		if (c == '\n') {
			break;	
		}
	}
	(*lineptr)[i] = '\0';

	return i;
}

