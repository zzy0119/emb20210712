#include <stdio.h>
#include <string.h>

#include "dlist.h"

#define NAMESIZE	32
#define N			3

typedef struct {
	char name[NAMESIZE];
	int age;
}person_t;

static void showPeron(const void *data)
{
	const person_t *d = data;

	printf("%s %d\n", d->name, d->age);
}

static int nameCmp(const void *data1, const void *data2)
{
	const person_t *d1 = data1;
	const person_t *d2 = data2;

	return strcmp(d2->name, d1->name);
}

int main(void)
{
	dlist_t *list;
	person_t p[N] = {
		{"yuyuanfei", 21},
		{"fenghaoran", 20},
		{"anxiaoxuan", 19}
	};
	int i;

	dlistHeadInit(&list, sizeof(person_t));
	
	for (i = 0; i < N; i++) {
		dlistInsert(list, p+i, DLISTTAILINSERT);	
	}
	dlistTraval(list, showPeron);

	dlistSort(list, nameCmp);
	dlistTraval(list, showPeron);

	dlistDestroy(list);

	return 0;
}

