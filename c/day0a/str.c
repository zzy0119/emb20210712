#include <stdio.h>
/*
 字符数组：存储字符串变量所使用的数据类型
 字符串:""内，由多个字符组成，'\0'结尾的
 */

int main(void)
{
	// 初始化 
	char s1[20] = "worldhello"; // 6
	char s2[] = {"world"};
	char s3[] = {'w', 'o', 'r', '\0','l', 'd', '\0'};
	char s4[] = {'a', 'b', 'c'};
	int i, j;
	int res;
#if 0
	for (i = 0; s1[i]; i++)
		printf("%c", s1[i]);
	printf("\n");
#endif
	puts(s1);

	for (i = 0; s1[i]; i++)
		;
	printf("长度为:%d\n", i);

	// 复制
#if 0
	for (i = 0; s2[i]; i++)
		s1[i] = s2[i];
	s1[i] = '\0';
	puts(s1);
#endif
#if 0
	i = 0;
	while (s1[i] = s2[i])
		i++;
	puts(s1);
	for (i = 0; s1[i]; i++)			
		;
	for (j = 0; s2[j]; j++)
		s1[i+j] = s2[j];
	s1[i+j] = '\0';
	puts(s1);
#endif

	// 字符串大小
	i = 0;
	res = 0;
	while (s1[i] || s2[i]) {
		if (s1[i] != s2[i]) {
			res = s1[i] - s2[i];			
			break;
		}
		i++;	
	}
	printf("res:%d\n", res);

	if (res == 0) {
		printf("相等\n");
	} else if (res > 0) {
		printf("s1大\n");
	} else {
		printf("s2大\n");
	}

	return 0;
}

