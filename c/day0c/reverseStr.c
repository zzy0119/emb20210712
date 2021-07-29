#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *revserStr(const char *p)
{
	int i, j;
	int cnt = 0;
	int len = strlen(p)+1;
	char *ret = malloc(len);
	if (NULL == ret)
		return NULL;
	memset(ret, 0, len);

	for (i = 0, j = len-2; j >= 0; i++, j--) {
		ret[i] = p[j];
		if (p[j] >= 'A' && p[j] <= 'Z')
			cnt ++;
	}

	// 拼接所有的大写字母
	if (cnt > 0)
		ret = realloc(ret, cnt+len);
	for (i = 0, j = 0; p[j]; j++) {
		if (p[j] >= 'A' && p[j] <= 'Z') {
			ret[len-1+i] = p[j];	
			i++;
		}
	}
	ret[cnt+len-1] = 0;

	return ret;
}

int main(void)
{
	char *r = revserStr("hello world");
	puts(r);

	free(r);

	return 0;
}

