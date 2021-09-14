#include <stdio.h>
#include <string.h>

int main(void)
{
	char *p = strtok("\n", "\n");
	printf("%d\n", p == NULL);
	return 0;
}
