#include <stdio.h>

// 打印一行
static void printLine(int blankCnt, int starCnt)
{
	int i;
	for (i = 0; i < blankCnt; i++)
		printf("  ");
	for (i = 0; i < starCnt; i++)
		printf("* ");

	printf("\n");
}

// 打印菱形
void showDiamond(int line)
{
	int l;

	// 上
	for (l = 0; l < line/2+1; l++)
		printLine(line/2-l, 2*l+1);
	
	// 下
	for (l = line/2-1; l >= 0; l--)
		printLine(line/2-l, 2*l+1);

}



