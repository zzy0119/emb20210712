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

static int nameSort(const void *data1, const void *data2)
{
	const struct stu_st *d1 = data1;
	const struct stu_st *d2 = data2;

	return strcmp(d2->name, d1->name);
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
		{"zhangtao", 20},
		{"guanhongyang", 20},
		{"zhangyue", 19}
	};
	int i;
	char *delName = "张悦";

	seqlistInit(&sl, sizeof(struct stu_st));

	for (i = 0; i < N; i++) {
		// seqlistAdd(sl, stus+i);
		seqlistInsertSort(sl, stus+i, nameSort);
	}

	seqlistTraval(sl, showStu);

	printf("删除一个元素后\n");
	seqlistDel(sl, delName, nameCmp);
	seqlistTraval(sl, showStu);

	seqlistDestroy(sl);

	return 0;
}

