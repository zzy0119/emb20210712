#include <stdio.h>

int main(void)
{
	int a, b; // a千百b十个
	int i, num;

	for (a = 0; a < 10; a++) {
		for (b = 0; b < 10; b++) {
			if (a != b) {
				num = a*1000+a*100+b*10+b;
				for (i = 1; i < 100; i++) {
					if (i*i == num) {
						printf("i:%d\n", i);
						printf("车牌号是%d\n", num);
						break;
					}
				}
			}
		}
	}

	return 0;
}

