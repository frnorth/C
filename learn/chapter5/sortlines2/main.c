#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define defprint(x) printf(#x ": %d\n", x)

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int numcmp(const char *, const char *);

void qsort2(void *v[], int left, int right, int (*comp)(void *, void *));

/* sort input lines */
main(int argc, char *argv[])
{
	int nlines, num = 0; /* number of input lines read */

	if (argc == 2 && strcmp(*++argv, "-n") == 0)
		num = 1;
	defprint(num);
	if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
		qsort2((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(num ? numcmp : strcmp));
		printf(">>>>>>>>>>>>>>>>>>\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
