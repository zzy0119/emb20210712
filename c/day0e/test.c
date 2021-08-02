/*
 学生结构:
 	姓名
	年龄
	c语言成绩
读入10个学生信息，存储到用户开辟的存储空间中，并打印除所有及格的学生的信息
 */
#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE	32
#define N			2

struct stu_st {
	char name[NAMESIZE];
	int age;
	float score;
};

int main(void)
{
	struct stu_st *s;
	int i;

	s = calloc(N, sizeof(struct stu_st));
	if (NULL == s)
		return 1;
	for (i = 0; i < N; i++) {
		printf("输入该学生的姓名/年龄/成绩:");
		scanf("%s%d%f", s[i].name, &s[i].age, &s[i].score);
	}

	for (i = 0; i < N; i++)
		if (s[i].score >= 60)
			printf("%s %d %f\n", s[i].name, s[i].age, s[i].score);

	free(s);

	return 0;
}

