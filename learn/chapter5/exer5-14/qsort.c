#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define defprintf(x) printf(#x ": %f\n", x)
#define defprints(x) printf(#x ": %s\n", x)
int numcmp(const char *, const char *);

void qsort2(void *v[], int left, int right,
		int (*comp)(void *, void *),
		int reverse)
{
	int i, last;
	void swap(void *v[], int i, int j);

	if (left >= right)	/* do nothing if array contains */
		return;			/* fewer than two elements */
	swap(v, left, (left + right)/2);	/* move partition elem */
	last = left;						/* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
		if (reverse * (*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);	/* restore partition elem */
	qsort2(v, left, last - 1, comp, reverse);
	qsort2(v, left + 1, right, comp, reverse);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int numcmp(const char *s1, const char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	/*defprints(s1);
	defprints(s2);
	defprintf(v1);
	defprintf(v2);*/
	if (v1 > v2)
		return 1;
	else if (v1 < v2)
		return -1;
	else
		return 0;
}

int strcmpf(const char *s1, const char *s2)
{
	int equal = 0;
	const char *s = s1, *t = s2;

	for (; tolower(*s) == tolower(*t) ; s++, t++)
		if (*s == '\0')
			equal = 1;
	if (equal == 1) {
		for (s = s1, t = s2; *s == *t ; s++, t++)
			if (*s == '\0')
				return 0;
		return *t - *s;
	}
	return tolower(*s) - tolower(*t);
}
