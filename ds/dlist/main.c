#include <stdio.h>

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

int main(void)
{
	dlist_t *list;
	person_t p[N] = {
		{"于元飞", 21},
		{"冯浩然", 20},
		{"安晓宣", 19}
	};
	int i;

	dlistHeadInit(&list, sizeof(person_t));
	
	for (i = 0; i < N; i++) {
		dlistInsert(list, p+i, DLISTTAILINSERT);	
	}
	dlistTraval(list, showPeron);

	dlistDestroy(list);

	return 0;
}

