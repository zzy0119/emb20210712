#include <stdio.h>

/*
判断有多少个三位数满足同时不能被３和５整除
循环:
	1.
		for (循环变量初始化; 循环条件; 循环变量的改变) {
			循环体;
		}
	2. 
	while (循环条件) {
		循环体
	}
	3. 多用于错误检测
		do {
			循环体;
		} while (循环条件);
		循环体至少执行1次
	4.
		break; // 终止循环
		continue;　//结束当前循环体,继续下一次
 */
int main(void)
{
	int num;
	int cnt = 0;

	// 依次取出[100,1000)之间的每一个数，判断
	for (num = 100; num < 1000; num ++) {
		if (num % 3 && num % 5)
			cnt ++;
	}

	printf("有%d个\n", cnt);	

	return 0;
}

