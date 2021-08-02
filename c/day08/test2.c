#include <stdio.h>

int main(void)
{
	int key = 4;

	for (int i = 0; i < 4; i++) {
		// 1111 0000 10000
		if ((key & 0xf0) != 0)
			break;
		else
			key <<= 1;
	}
	printf("key:%d\n", key);	

	return 0;
}

