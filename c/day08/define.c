#include <stdio.h>

/*
 预处理指令:
#include
#ifndef
#endif
#ifdef
#define
#if
 */

// 宏定义
#define N	10
// 宏函数
#define SQUAR(x)	((x)*(x))

#define SWAP(x, y) \
	do {\
		typeof(x) t;\
		t = x;\
		x = y;\
		y = t;\
	} while(0)

int main(void)
{
	int i;
	int score;

#if 0
	for (i = 0; i < N; i++) {
		scanf("%d", &score);
		printf("%d\n", score);
	}
#endif

	score = 10;
	printf("%d\n", SQUAR(score+2));

	// 系统中定义的宏
	printf("%d\n", __LINE__);
	printf("%s\n", __FUNCTION__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	int m = 10, n = 20;

	SWAP(m, n);
	printf("m:%d, n:%d\n", m, n);

	return 0;
}





