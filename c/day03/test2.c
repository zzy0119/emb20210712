#include <stdio.h>

int main(void)
{
	int year, month, day;
	int sum = 0;
	int i;

	printf("请输入一个日期:");
	scanf("%d/%d/%d", &year, &month, &day);

	// year.1.1~year.month.1
#if 0
	for (i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || \
				i == 7 || i == 8 || i == 10 || \
				i == 12)
			sum += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			sum += 30;
		else
			sum += ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28);
	}
#endif
	switch (month - 1) {
		case 11:
			sum += 30;
		case 10:
			sum += 31;
		case 9:
			sum += 30;
		case 8:
			sum += 31;
		case 7:
			sum += 31;
		case 6:
			sum += 30;
		case 5:
			sum += 31;
		case 4:
			sum += 30;
		case 3:
			sum += 31;
		case 2:
			sum += 28 + (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
		case 1:
			sum += 31;
			break;
		default:
			break;
	}

	sum += day;

	printf("%d/%d/%d是这一年的第%d天\n", year, month, day, sum);

	return 0;
}

