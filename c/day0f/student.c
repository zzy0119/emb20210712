#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMESIZE	32
#define NUMSIZE		12
#define N			5

typedef struct {
	char name[NAMESIZE];
	long no;
	int age;
	char telNum[NUMSIZE];
}stu_t;

typedef int (*delcmp_t)(const void *key, const stu_t *s);
int delStu(stu_t **s, int *nmemb, const void *key, delcmp_t cmp);
int addStu(stu_t **s, int *nmemb,stu_t stu);
void showStu(const stu_t *s, int nmemb);

static int nameCmp(const void *key, const stu_t *s)
{
	char **k = key;

	return strcmp(*k, s->name);
}

static int ageCmp(const void *key, const stu_t *s)
{
	const int *k = key;

	return *k - s->age;
}

int main(void)
{
	stu_t arr[N] = {
		{"刘泽峰", 1, 20, "13711371234"}, 
		{"吴雨珩", 2, 19, "18911118882"},
		{"徐子婷", 3, 20, "18611224455"},
		{"安晓宣", 4, 20, "11801129988"},
		{"武子涵", 5, 18, "11644557892"}
	}; 	
	stu_t *start = NULL;	
	int n = 0;
	int i;

	for (i = 0; i < N; i++)
		addStu(&start, &n, arr[i]);
	showStu(start, n);

	printf("××××××××××名字删除×××××××\n");
	char *delName = "吴雨珩";
	delStu(&start, &n, &delName, nameCmp);
	showStu(start, n);
	printf("××××××××××年龄删除×××××××\n");
	int delAge = 20;
	delStu(&start, &n, &delAge, ageCmp);
	showStu(start, n);

	return 0;
}

// 增
/*
s:存储学生管理系统首地址的指针变量的地址
nmemb:成员个数变量的地址
stu:要增加的学生信息
return: 0成功 -1失败
 */
int addStu(stu_t **s, int *nmemb,stu_t stu)
{
	*s = realloc(*s, (*nmemb+1)*sizeof(stu_t));
	if (NULL == *s)
		return -1;
	// memcpy(*s+*nmemb, &stu, sizeof(stu_t));
	(*s)[*nmemb] = stu;
	(*nmemb)++;

	return 0;
}
	
// 遍历
void showStu(const stu_t *s, int nmemb)
{
	int i;

	for (i = 0; i < nmemb; i++) {
		printf("%s %ld %d %s\n", s[i].name, s[i].no, \
				s[i].age, s[i].telNum);
	}
}

// 删除
int delStu(stu_t **s, int *nmemb, const void *key, delcmp_t cmp)
{
	int i;	

	for (i = 0; i < *nmemb; i++) {
		if (cmp(key, *s+i) == 0) {
			memcpy(*s+i, *s+i+1, (*nmemb-i-1)*sizeof(stu_t));	
			(*nmemb)--;
			*s = realloc(*s, *nmemb*sizeof(stu_t));
			i--;
		}
	}

	return 0;
}







