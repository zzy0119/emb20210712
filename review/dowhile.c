#include <stdio.h>

int main(void)
{
	int score;
	int res = 0;

	do {
		scanf("%d", &score);
	} while (!(score >= 0 && score <= 100));

	while (1) {
		n = score % 10;
		score /= 10;
		if (n % 2) {
			continue;
		}
		res = res * 10 + n;
		if (score == 0)
			break;
	}	


	return 0;
}

