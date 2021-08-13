#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stack.h>

char *infixToPreinfix(const char *ptr);
int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;
				
	puts(infixToPreinfix(argv[1]));

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

char *infixToPreinfix(const char *ptr)
{
	stack_t *opS, *resS;	
	int len;
	char top;
	int i, size;
	char *res;

	len = strlen(ptr);

	stackInit(&opS, sizeof(char), len);
	stackInit(&resS, sizeof(char), len);

	while (--len >= 0) {
		if (isNumber(ptr[len]))
			stackPush(resS, ptr+len);
		else if (isOperator(ptr[len])) {
			while (!stackIsEmpty(opS)) {
				stackPop(opS, &top);
				if (opratorValue(top) <= opratorValue(ptr[len])) {
					stackPush(opS, &top);
					break;
				} else {
					stackPush(resS, &top);	
				}
			}
			stackPush(opS, ptr+len);
		} else if (ptr[len] == ')')
			stackPush(opS, ptr+len);
		else if (ptr[len] == '(') {
			while (!stackIsEmpty(opS)) {
				stackPop(opS, &top);
				if (top == ')')
					break;
				stackPush(resS, &top);
			}
			if (stackIsEmpty(opS) && top != ')')
				goto ERROR;
		} else {
			goto ERROR;
		}
	}

	while (!stackIsEmpty(opS)) {
		stackPop(opS, &top);
		stackPush(resS, &top);
	}

	stackDestroy(opS);

	size = 1;
	i = 0;
	res = NULL;
	while (!stackIsEmpty(resS)) {
		res = realloc(res, size+1);		
		stackPop(resS, res+i);	
		i++;
		size ++;
	}
	res[i] = '\0';

	stackDestroy(resS);

	return res;

ERROR:
	stackDestroy(opS);
	stackDestroy(resS);

	return NULL;
}




