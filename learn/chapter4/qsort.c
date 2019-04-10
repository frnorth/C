#include <stdio.h>

void qsort(int v[], int left, int j);

main()
{
	int i;
	int array[] = {54, 57, 214, 36, 21, 1, 35, 3, 68, 87, 156, 233, 124};

	for (i = 0; i < 13; i++)
		printf("%d  ", array[i]);
	printf("\n");
	qsort(array, 1, 11);
	for (i = 0; i < 13; i++)
		printf("%d  ", array[i]);
	printf("\n");
	
}

void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)	/* do nothing if array contains */
		return;			/* fewer than two elements */
	swap(v, left, (left + right)/2);	/* move partition elem */
	last = left;						/* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);	/* restore partition elem */
	qsort(v, left, last - 1);
	qsort(v, left + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
