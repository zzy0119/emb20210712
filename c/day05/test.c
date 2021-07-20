#include <stdio.h>

int isLeap(int year);
int monthDays(int m, int y);
int main(void)
{
	int month, year;

	scanf("%d%d", &year, &month);

	printf("%d\n", monthDays(month, year));

	return 0;
}

int monthDays(int m, int y)
{
	int day;

	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day = 30;
			break;
		case 2:
			day = 28 + isLeap(y);			
			break;
		default:
			day = -1;
			break;
	}

	return day;
}

int isLeap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
