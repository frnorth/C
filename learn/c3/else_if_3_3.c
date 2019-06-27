#include<stdio.h>

#define LENGTH 100
#define SEARCH 10

int binsearch(int x, int v[], int n);
/* binsearch2 is the exercise 3-1 */
int binsearch2(int x, int v[], int n);

main()
{
	int i, site1, site2;
	int v[LENGTH];

	for(i = 0; i < LENGTH; i++)
		v[i] = i * i;

	site1 = binsearch(SEARCH, v, LENGTH);
	site2 = binsearch2(SEARCH, v, LENGTH);
	printf("%dth element of v is %d, searched by 1\n", site1, v[site1]);
	printf("%dth element of v is %d, searched by 2\n", site2, v[site2]);

	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high)/2;
		if(x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low + high)/2;
		if(x <= v[mid])
			high = mid;
		else
			low = mid + 1;
	}
	if(x == v[high])
		return high;
	else
		return -1;
}
