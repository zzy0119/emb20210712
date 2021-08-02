#include <stdio.h>

enum {LEFT='a', RIGHT='d', UP='w', DOWN='s'};

int main(void)
{
	int ch;

	ch = getchar();
	switch (ch) {
		case LEFT:
			printf("正在向左移动...\n");
			break;
		case RIGHT:
			printf("正在向右移动....\n");
			break;
		case UP:
			printf("正在向上移动....\n");
			break;
		case DOWN:
			printf("正在向下移动....\n");
			break;
		default:
			break;
	}


	return 0;
}
