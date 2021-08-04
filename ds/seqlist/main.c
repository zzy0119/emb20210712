#include <stdio.h>
#include <string.h>
#include "seqlist.h"

#define NAMESIZE	32
#define N		 	3	
struct stu_st {
	char name[NAMESIZE];
	int age;
};

static void showStu(const void *data)
{
	const struct stu_st *d = data;

	printf("%s %d\n", d->name, d->age);
}

static int nameCmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const char *k = key;

	return strcmp(d->name, k);
}

int main(void)
{
	seqlist_t *sl = NULL;
	struct stu_st stus[N] = {
		{"张涛", 20},
		{"关红阳", 20},
		{"张悦", 19}
	};
	int i;
	char *delName = "张悦";

	seqlistInit(&sl, sizeof(struct stu_st));

	for (i = 0; i < N; i++) {
		seqlistAdd(sl, stus+i);
	}

	seqlistTraval(sl, showStu);

	printf("删除一个元素后\n");
	seqlistDel(sl, delName, nameCmp);
	seqlistTraval(sl, showStu);

	seqlistDestroy(sl);

	return 0;
}

