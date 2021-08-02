#include <stdio.h>
#include <stdlib.h>

char *mygetline(void);
int main(void)
{
	char *r = NULL;

	mygetline(&r);
	puts(r);

	free(r);

	return 0;
}

/*
 从终端读入一行字符串
 */
void mygetline(char **ptr)
{
	char *ret = NULL;
	int i = 0;
	int size = 1;

	while (1) {
		ret = realloc(ret, size);
		ret[i] = getchar();
		if (ret[i] == '\n') {
			ret[i] = '\0';
			break;
		}
		size ++;
		i++;
	}

	*ptr = ret;
}


