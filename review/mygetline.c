#include <stdio.h>
#include <stdlib.h>

#define SIZE	10

int mygetline(char **lineptr, int *n);
int main(void)
{
	char *ptr = NULL;
	int size = 0;

	mygetline(&ptr, &size);
	puts(ptr);

	free(ptr);

	return 0;
}

int mygetline(char **lineptr, int *n)
{
	int i;

	if (*lineptr == NULL && *n == 0) {
		*lineptr = malloc(SIZE);
		if (NULL == *lineptr)
			return -1;
		*n = SIZE;
	}

	i = 0;
	while (1) {
		// 空间足够
		if (i+2 > *n) {
			*n += SIZE;
			*lineptr = realloc(*lineptr, *n);
			if (NULL == *lineptr)
				return -1;
		}
		(*lineptr)[i] = getchar();
		if ((*lineptr)[i] == '\n' ) {
			i++;
			break;	
		}
		if ((*lineptr)[i] == EOF) 
			break;
		i++;
	}
	(*lineptr)[i] = '\0';

	return i;
}


