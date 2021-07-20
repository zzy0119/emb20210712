/*
 已知1990.1.1是星期一
 读入用户输入的任意1990年后年月,打印出相应的日历
 */
#include <stdio.h>

int main(void)
{
	int year, month;
	int sumdays = 0;
	int i;
	int weekday, monthdays;

	// 读入用户输入的年月--->判断是否符合1990后月份是否在1~12
	do {
		printf("年/月:");	
		scanf("%d/%d", &year, &month);
	} while (year < 1990 || month < 1 || month > 12);

	// 统计y/m/1~1990.1.1经过了多少天sumdays
	// [1990,y)+y/1/1~y/m/1---->sumdays
	for (i = 1990; i < year; i++) {
		sumdays += (i % 4 == 0 && i % 100 != 0 || \
			   i % 400 == 0 ? 366 : 365);
	}
	switch (month-1) {
		case 11:
			sumdays += 30;
		case 10:
			sumdays += 31;
		case 9:
			sumdays += 30;
		case 8:
			sumdays += 31;
		case 7:
			sumdays += 31;
		case 6:
			sumdays += 30;
		case 5:
			sumdays += 31;
		case 4:
			sumdays += 30;
		case 3:
			sumdays += 31;
		case 2:
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				sumdays += 29;
			else 
				sumdays += 28;
		case 1:
			sumdays += 31;
			break;
		default:
			break;
	}
	sumdays += 1;
	// y/m/1是星期几?
	weekday = sumdays % 7;
	printf("%d/%d/1是星期%d\n", year, month, weekday);

	// m月有多少天
	if (month == 1 || month == 3 || month == 5 \
			|| month == 7 || month == 8 || \
			month == 10 || month == 12)
		monthdays = 31;
	else if (month == 4 || month == 6 || \
			month == 9 || month == 11)
		monthdays = 30;
	else
		monthdays = year % 4 == 0 && year % 100 != 0 || \
				  year % 400 == 0 ? 29 : 28;

	// 日历打印
	printf("    %d月 %d\n", month, year);
	printf("日 一 二 三 四 五 六\n");
	for (i = 0; i < weekday; i++)
		printf("   ");	
	for (i = 1; i <= monthdays; i++) {
		printf("%2d", i);
		//　间隔空格或者换行 
		printf("%c", (i + weekday) % 7 == 0 ? '\n' : ' ');
	}
	printf("\n");

	return 0;
}

