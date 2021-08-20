#include <stdio.h>

#define BUFSIZE	100

int main(int argc, char *argv[])
{
	char buf[BUFSIZE] = {};
	FILE *fp = NULL;

	if (argc < 2)
		return 1;

	fp = fopen(argv[1], "r");
	// if error

	int n;	
	fseek(fp, 10, SEEK_SET);
	n = ftell(fp); // 获取当前文件偏移量
	printf("%d\n", n);
	rewind(fp); // pos = 0
	n = ftell(fp); // 获取当前文件偏移量
	printf("%d\n", n);

	printf("hello world");
	fprintf(stderr, "good morning");

	snprintf(buf, BUFSIZE, "%s", argv[1]);
	puts(buf);

	while (1)
		;
	return 0;
}


