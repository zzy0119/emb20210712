#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 将命令行第二个参数和第三个参数，拼接为一个新的字符串输出
 */
int main(int argc, char *argv[])
{
	char *res;

	if (argc < 3)
		return 1;
	int size = strlen(argv[1]) + strlen(argv[2]) + 1;

	res = malloc(size);
	memset(res, '\0', size);

	strcpy(res, argv[1]);
	strcat(res, argv[2]);

	puts(res);

	free(res);
	return 0;
}

