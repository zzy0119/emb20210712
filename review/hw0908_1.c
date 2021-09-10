#include <stdio.h>
#include <stdlib.h>

#include "day.h"

int main(int argc, char *argv[])
{
	int sum = 0;

	if (argc < 4)	
		return 1;
	sum = sumdays(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	if (sum % 5 < 3) {
		printf("打渔\n");
	}else
		printf("晒网\n");
	
	return 0;
}

