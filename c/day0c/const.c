#include <stdio.h>

int main(void)
{
	char str[] = "good morning";
	const char *p = str; // 常量指针:*p只读
	// char const *p
	char *const q = str; // 指针常量:q只读	

//	*p = 'm';
	p++;
	*q = 'm';
	q++;

	return 0;
}

