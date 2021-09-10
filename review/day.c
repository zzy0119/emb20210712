#include "day.h"

int isLeap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int daysOfMonth(int month, int year)
{
	int ret;
	int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	ret = days[month];
	if (month == 2) {
		ret += isLeap(year);
	}
	return ret;
}

int sumdays(int year, int month, int day)
{
	int sum = 0;
	int i;

	for (i = BASEYEAR; i < year; i++)
		sum += (isLeap(i) ? 366 : 365);
	for (i = 1; i < month; i++)
		sum += daysOfMonth(i, year);
	sum += day;

	return sum;
}





