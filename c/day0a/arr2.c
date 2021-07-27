#include <stdio.h>
#include <unistd.h>

static int arr[4][4] = {
		{0,0,0,0},	
		{0,1,0,0},	
		{0,1,1,0},	
		{0,1,0,0}
};
static int startx=1, starty=1;

static void draw()
{
	int i, j;
	
	printf("\e[2J"); // 清屏
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (arr[i][j]) {
				printf("\033[43m\033[%d;%dH[]", i+startx, 2*j+starty);
				printf("\033[0m");
			}
		}
	}
	printf("\n");
}

int main(void)
{

//	printf("\033[%d;%dH[]", 5, 8);
	while (1) {
		draw();
		startx ++;
		sleep(1);
	}

	return 0;
}

