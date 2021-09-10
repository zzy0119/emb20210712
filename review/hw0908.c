/*
 1. 如果一个渔夫从 2011 年 1 月 1 日开始每三天打一次渔，两天晒一次网，编程实现当输入 2011 1 月 1 日以后的任意一天，输出该渔夫是在打渔还是在晒网。

 2. 编号为 1，2，3，…，n 的 n 个人围坐一圈，任选一个正整数 m 作为报数上限值，从第一个人开始按顺时针方向报数，报数到 m 时停止，报数为 m 的人出列。从出列人的顺时针方向的下一个人开始又从 1 重新报数，如此下去，直到所有人都全部出列为止。

 */
#include <stdio.h>
#include <stdlib.h>

void josephu(int nmemb, int m);

int main(int argc, char *argv[])
{
	if (argc < 3)
		return 1;
	josephu(atoi(argv[1]), atoi(argv[2]));

	return 0;
}

void josephu(int nmemb, int m)
{
	int *arr = calloc(nmemb, sizeof(int));
	int i, j;
	int cnt = 0;

	for(i = 0; i < nmemb; i++) {
		arr[i] = i+1;
	}
	
	for (i = 0; cnt < nmemb ; i = (i+1) % nmemb) {
		j = 1; // 开始数数
		while (j < m) {
			while (arr[i] == 0) {
				// 此人已淘汰
				i = (i+1) % nmemb;
			}
			j++;
			i = (i+1) % nmemb;
		}
		// 到m
		while (arr[i] == 0)
			i = (i+1) % nmemb;
		printf("%d淘汰\n", arr[i]);
		arr[i] = 0;
		cnt ++;
	}
	free(arr);
}



