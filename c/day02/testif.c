#include <stdio.h>

/*
 读入一个学生的成绩，判断其所属于的等级
 90~100	A
 80~89	B
 70~79	C
 60~69	D
 0~59	E
 */
int main(void)
{
	int score;

	printf("score:");
	scanf("%d", &score);

	if (!(score >= 0 && score <= 100)) {
		printf("成绩无效\n");
		return 1;
	}
/*
	if (90 <= score && score <= 100)
		printf("A\n");
	else if (score >= 80 && score <= 90) 
		printf("B\n");
	else if (score >= 70 && score <= 79) 
		printf("C\n");
	else if (score >= 60 && score <= 69) 
		printf("D\n");
	else 
		printf("E\n");
*/
	switch (score / 10) {
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;
	
	}




	return 0;
}

