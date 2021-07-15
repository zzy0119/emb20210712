#include <stdio.h>

int main(void)
{
	int fifty, twenty, ten, five;
	int cnt = 0;

	for (fifty = 1; fifty <= 10; fifty++) {
		for (twenty = 1; twenty <= 25; twenty ++) {
			for (ten = 1; ten <= 50; ten ++) {
				for (five = 1; five <= 100; five++) {
					if (fifty*50 + twenty*20 + ten*10 + five*5 == 500) {
						printf("50:%d, 20:%d, 10:%d, 5:%d\n", fifty, twenty, ten, five);
						cnt ++;
					}
				}
			}
		}
	}

	printf("cnt:%d\n", cnt);

	return 0;
}

