#include <stdio.h>
#include <string.h>

#define NAMESIZE	32

/*
 结构体
 struct stu_st--->整体是定义的学生类型
 */
struct stu_st {
	char name[NAMESIZE];
	int age;
	float score;
};

int main(void)
{
	// 定义结构体类型变量
	struct stu_st s1;
	// 初始化
	struct stu_st s2 = {"伟杰", 21, 98};
	// 指针
	struct stu_st *p = &s1;
	struct stu_st arr[3] = {
		{"hello", 1, 1},
		{"world", 1, 20},
		{"monday", 2, 20}
	};

	// 赋值
	strncpy(s1.name, "子涵", NAMESIZE);
	s1.age = 20;
	s1.score = 100;

	// 遍历
	printf("%s %d %f\n", s1.name, s1.age, s1.score);

	printf("%s %d %f\n", s2.name, s2.age, s2.score);
	// 指针访问成员变量
	printf("%s %d %f\n", p->name, p->age, p->score);

	return 0;
}
	
