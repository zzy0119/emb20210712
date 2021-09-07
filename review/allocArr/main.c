#include <stdio.h>
#include <string.h>

#include "allocArr.h"

#define TELSIZE	12

struct data_st {
	char tel[TELSIZE];
	int id;
};

static void show(const void *data)
{
	const struct data_st *d = data;
	printf("%s %d\n", d->tel, d->id);
}

static int strCmp(const void *data, const void *key)
{
	const struct data_st *d = data;
	const char *k = key;
	return strcmp(d->tel, k);
}

int main(int argc, char *argv[])
{
	arr_t *arr;
	struct data_st data[3] = {
		{"13655789542", 1},
		{"13655769742", 2},
		{"13655703972", 3}
	};

	init(&arr, sizeof(struct data_st));
	
	for (int i = 0; i < 3; i++) 
		add(arr, data+i);
	traval(arr, show);

	del(arr, "13655769742", strCmp);
	traval(arr, show);

	return 0;
}

