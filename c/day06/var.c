#include <stdio.h>

/*
 变量:
 	定义:type name;-->分配存储空间
	声明:不占用存储空间
	初始化:type name = value;
	赋值:name = value;
 分类:
 	局部变量:
		定义在函数体内
		作用域:在函数内
		生存周期:随着函数调用结束而消亡
		未初始化值为随机值
	全局变量:
		定义在函数体外
		作用域:整个文件(进程)
		生存周期:随着进程的终止而消亡
		能用局部变量就不选择全局变量
		未初始化值为0
	块变量:在语句内,for、while、if
		作用域:语句块内
		生存周期:同局部变量
		未初始化值随机
 修饰变量的关键字:
auto:默认自动变量
const:只读变量
static:静态变量
	<1>修饰局部变量:延长生存周期到进程终止，未初始化值为0,作用域不变
	<2>修饰全局变量:限制在多文件的进程中此全局变量的作用域只在本文件中
	<3>修饰函数:限制函数的作用域在本文件中
register:寄存器变量
extern:外部声明变量
volatile:易失变量:防止编译优化
 */

static int glob; // 全局变量

// 函数的参数--->形参(局部变量)
void test(int n)
{
	// static int var; // 局部静态变量,未初始化值为0
	int var = 0;
	var ++;

	printf("var:%d\n", var);
// 	printf("glob:%d\n", glob);
}

int main(void)
{
	auto int var, var1, var2, var3; // 局部变量的定义
	const int n = 10; // n只读变量
	int i = 1;

	// 函数的传参的次序是至右向左
	printf("%d %d %d\n", i++, i++, i++);

	// n ++;

	glob = 100;

	test(10);
	test(10);
	test(10);
	test(10);

	for (int i = 0; i < 5; i++)
		printf("*");
	printf("var:%d, var1:%d, var2:%d, var3:%d\n", var, var1, var2, var3);

	return 0;
}

