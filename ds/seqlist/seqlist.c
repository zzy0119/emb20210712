#include <stdlib.h>
#include <string.h>

#include "seqlist.h"

int seqlistInit(seqlist_t **s, int size)
{
	*s = malloc(sizeof(seqlist_t));
	if (NULL == *s)
		return -1;
	(*s)->p = NULL;
	(*s)->nmemb = 0;
	(*s)->size = size;

	return 0;
}

int seqlistAdd(seqlist_t *s, const void *data)
{
	s->p = realloc(s->p, (s->nmemb+1)*s->size);
	if (s->p == NULL)
		return -1;
	memcpy((char *)s->p + s->nmemb * s->size, data, s->size);
	(s->nmemb)++;

	return 0;
}

void seqlistTraval(const seqlist_t *s, pri_t pri)
{
	int i;

	for (i = 0; i < s->nmemb; i++) {
		pri((char *)s->p + i*s->size);
	}
}





