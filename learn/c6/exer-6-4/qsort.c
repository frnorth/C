#include <string.h>
#include <stdio.h>
#include "tnode.h"

void qsort2(struct tnode *v[], int left, int right)
{
	int i, last;
	void swap(struct tnode *v[], int i, int j);
	int cmptnode(struct tnode *t1, struct tnode *t2);

	if (left >= right)	/* do nothing if array contains */
		return;			/* fewer than two elements */
	swap(v, left, (left + right)/2);	/* move partition elem */
	last = left;						/* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
		if (cmptnode(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);	/* restore partition elem */
	qsort2(v, left, last - 1);
	qsort2(v, left + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(struct tnode *v[], int i, int j)
{
	struct tnode *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int cmptnode(struct tnode *t1, struct tnode *t2)
{
	if (t1->count < t2->count) {
		//defprint(d, t1->count);
		return -1;
	}
	else if (t1->count > t2->count)
		return 1;
	else
		return -1 * strcmp(t1->word, t2->word);
}
