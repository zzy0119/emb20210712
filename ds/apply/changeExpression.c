#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stack.h>
#include <queue.h>

char *infixToPostfixExpression(const char *ptr);
int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;

	char *ret = infixToPostfixExpression(argv[1]);
	puts(ret);

	return 0;
}

static int isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static int isNumber(char ch)
{
	return ch >= '0' && ch <= '9';
}

static int opratorValue(char ch)
{
	int ret = 0;

	if (ch == '+' || ch == '-')
		ret = 1;
	else if (ch == '*' || ch == '/')
		ret = 2;

	return ret;
}

char *infixToPostfixExpression(const char *ptr)
{
	stack_t *s;
	queue_t *q;
	int len;
	char popElm;
	char *retExp;
	int i;
	int size;

	len = strlen(ptr);

	// 运算符
	stackInit(&s, sizeof(char), len);
	// 结果队列
	q = queueInit(len+1, sizeof(char));

	while (*ptr) {
		if (isOperator(*ptr)) {
			while (!stackIsEmpty(s)) {
				stackPop(s, &popElm);
				if (opratorValue(*ptr) <= opratorValue(popElm)) {
					enq(q, &popElm);	
				} else {
					// 栈顶运算符优先级低于要入栈元素
					stackPush(s, &popElm);
					break;
				}
			}
			stackPush(s, ptr);	
		} else if (isNumber(*ptr))
			enq(q, ptr);
		else if (*ptr == '(')
			stackPush(s, ptr);
		else if (*ptr == ')') {
			while (1) {
				if (stackIsEmpty(s))
					goto ERROR;
				stackPop(s, &popElm);
				if (popElm == '(')
					break;
				enq(q, &popElm);
			}
		} else 
			goto ERROR;
		ptr ++;
	}

	while (!stackIsEmpty(s)) {
		stackPop(s, &popElm);
		enq(q, &popElm);
	}

	stackDestroy(s);

	i = 0;
	size = 1; // '\0'
	retExp = NULL;
	while (!queueIsEmpty(q)) {
		deq(q, &popElm);
		retExp = realloc(retExp, (size+1)*sizeof(char));	
		retExp[i++] = popElm;
		size ++;
	}
	retExp[i] = '\0';

	queueDestroy(q);
	
	return retExp;

ERROR:
	stackDestroy(s);
	queueDestroy(q);
	return NULL;
}





