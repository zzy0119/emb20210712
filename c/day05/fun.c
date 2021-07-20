#include <stdio.h>

/*
 函数的声明:调用之前声明
 返回值类型 函数名(参数列表类型);
 */
int isLeap(int year);

int main(void)
{
	int y;
	int ret;

	scanf("%d", &y);

	/*
	 函数的调用:
	 	var = 函数名(传递的值);
	 */
	ret = isLeap(y); // year = y
	if (ret) {
		printf("%d年是闰年\n", y);	
	} else {
		printf("%d年不是闰年\n", y);	
	}

	return 0;
}

/* 
函数的定义:
	返回值类型 函数名(参数列表)
	{
		函数体;	
	}
	参数列表:
		已知条件
	返回值类型:
		函数使用后的结果值
	函数体:
		实现功能
*/
// 判断给定的年份是否为闰年
int isLeap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}





