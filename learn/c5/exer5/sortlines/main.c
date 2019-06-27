#include <stdio.h>
#include <string.h>

#define MAXLINES 500 /* max lines to be sorted */
#define MAXLEN 5000 /* max lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *array, int maxlen);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main()
{
	int nlines; /* number of input lines read */
	char array[MAXLEN];

	if ((nlines = readlines(lineptr, MAXLINES, array, MAXLEN)) > 0) {
		//writelines(lineptr, nlines);
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
