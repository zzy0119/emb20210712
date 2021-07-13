#include <stdio.h>

/*
 存储空间进位:
 	8bit-->1byte
	1024bytes--->1k
	1024k--->1M
	1024M--->1G

 基本类型: 32位/64位
 	字符类型:
		char 1 / 1 printf("%c")
 	整型:
		short(2/2)(%hd) int(4/4)(%d) long(4/8)(%ld) (long long)(8/8)
	实型:
		float(4/4)(%f) doule(8/8)(%lf) (long double)(8/16)
	空类型:
		void
	复合类型:
		struct union

	符号:
		signed(default) / unsigned
标识符:
	变量名、函数名、类型名
	命名规则:
		由字母数字下划线组成，数字不开头,顾名思义并且避开ｃ关键字
ｃ关键字:
	特殊含义
	int char ...
	if while switch ....
	continue break
	sizeof
 */

int main(void)
{
	// 定义变量--->分配存储空间
	// type name;
	int n, m;
	char ch;

	// 读入的整型值存储到n变量对应的存储空间中
	scanf("%d/%d", &n, &m);
	printf("n:%d, m:%d\n", n, m);
	scanf("%c", &ch);

	printf("%ld\n", sizeof(long long));

	printf("%ld\n", sizeof(long double));

	return 0;
}
