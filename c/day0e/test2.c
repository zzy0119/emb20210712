#include <stdio.h>

#define NAMESIZE	32
#define COURSELEN	32

struct person_st {
	char name[NAMESIZE];
	int num;
	char sex;
	char profession;
	union {
		float score;
		char course[COURSELEN];
	}s_c;
};

int main(void)
{
	struct person_st p1;
	p1.s_c.score = 100;

	return 0;
}

