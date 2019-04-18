#include <stdio.h>

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if ((allocp + n) <= (allocbuf + ALLOCSIZE)) {
		allocp += n;
		printf("alloc allocp: %d\n", allocp);
		printf("alloc return: %d\n", allocp - n);
		return (allocp - n);
	}
	else
		return 0;
}

void afree(char *p)
{
	if (p >= allocbuf && p < (allocbuf + ALLOCSIZE))
		allocp = p;
	printf("afree allocp: %d\n", allocp);
}
