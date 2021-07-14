#include <stdio.h>

/*
 条件分支语句:
 1.
 	if (condition) {
 		statement;
 	}

 2.　
 	if (condition) {
		满足语句;
	} else {
		否则;
	}

 3. 
	if (condition1) {
	
	} else if (condition2) {
	
	} else if (condition3) {
	
	} else {
	
	}
 4.
 	switch (常量值/常量表达式) {
		case value1:
			statement1;
			break; // 结束分支
		case value2:
			....
		defualt:
			// else
			break;
	}

 */

int main(void)
{
	int score;

	printf("请输入您的成绩:");
	scanf("%d", &score);

	if (score < 0 || score > 100) {
		printf("请输入有效成绩\n");
	} else if (score >= 60) {
		printf("做的好!...\n");
	} else {
		printf("继续努力...\n");
	}


	return 0;
}

