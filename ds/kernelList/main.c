#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

#define NAME	32

struct stu_st {
	char name[NAME];
	int age;
	struct list_head node;
};

int main(void)
{
	struct stu_st *s;
	char *names[3] = {"lily", "lucy", "cala"};
	int ages[3] = {19, 20, 18};
	struct list_head *pos;

	LIST_HEAD(head);

	for (int i = 0; i < 3; i++) {
		s = malloc(sizeof(struct stu_st));
		if (NULL == s)
			return 1;
		strncpy(s->name, names[i], NAME);
		s->age = ages[i];
		list_add(&s->node, &head);
	}
	// 遍历
	list_for_each(pos, &head) {
		s = list_entry(pos, struct stu_st, node);
		printf("%s %d\n", s->name, s->age);
	}	


	return 0;
}

