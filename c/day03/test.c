#include <stdio.h>

int main(void)
{
	int n, t;
	int res = 0;

	for (n = 1000; n < 10000; n++) {
		t = n;	
		res = 0;
		while (t) {
			res = res * 10 + t % 10;
			t /= 10;
		}
		if (res == n * 9) {
			printf("%d\n", n);
			break;
		}
	}
	
	return 0;
}
