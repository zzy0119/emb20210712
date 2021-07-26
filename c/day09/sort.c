#include <stdio.h>

int main(void)
{
	int arr[] = {3,1,4,7,9,3,5,8,6};
	int i, j;
	int t, tmp;

	int nmeb = sizeof(arr) / sizeof(int);

	// 冒泡排序
	// 比较多少趟
	for (i = 0; i < nmeb-1; i++) {
		// 每一趟所要比较元素的下标范围
		for (j = 0; j < nmeb-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}
	for (i = 0; i < nmeb; i++)
		printf("%d ", *(arr+i));
	printf("\n");
	
	// 选择:无序序列中最大的元素放到起始地址
	// 选择的位置:
	for (i = 0; i < nmeb-1; i++) {
		// 找到最大值t
		t = i;
		for (j = i+1; j < nmeb; j++) {
			if (arr[j] > arr[t])
				t = j;
		}
		if (t != i) {
			// 交换
			tmp = arr[i];
			arr[i] = arr[t];
			arr[t] = tmp;
		}
	}
	for (i = 0; i < nmeb; i++)
		printf("%d ", *(arr+i));
	printf("\n");

	// 直接插入排序(从小到大)
	// 从无序序列中依次选择每一个元素插入到有序序列中
	// 选择待插入的元素
	for (i = 1; i < nmeb; i++) {
		t = arr[i];	
		// 依次遍历有序序列中的每一个元素
		for (j = i-1; j >= 0; j--) {
			if (t < arr[j])
				arr[j+1] = arr[j];
			else
				break;
		}
		// 插入t
		arr[j+1] = t;
	}


	for (i = 0; i < nmeb; i++)
		printf("%d ", *(arr+i));
	printf("\n");

	return 0;
}

