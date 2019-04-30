#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define defprint(x) printf(#x ": %d\n", x)

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int);
void writelines(char *lineptr[], int, int);
int numcmp(const char *, const char *);
int strcmpf(const char *, const char *);

void qsort2(void *v[], int, int,
		int (*)(void *, void *),
		int );

/* sort input lines */
main(int argc, char *argv[])
{
	int c, nlines, reverse = 1, numeric = 0, fold = 0, directory = 0; /* number of input lines read */
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = -1;
				break;
			case 'f':
				fold = 1;
				break;
			case 'd':
				directory = 1;
				break;
			default:
				printf("%c maybe a wrong parameter\n", c);
				return -1;
				break;
			}

	defprint(numeric);
	defprint(reverse);
	defprint(fold);
	defprint(directory);

	if (argc != 0) {
		printf("Maybe too many parameter\n", c);
		return -1;
	}

	if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
		qsort2((void **)lineptr, 0, nlines - 1,
			(int (*)(void *, void *))(numeric ? numcmp : (fold? strcmpf : strcmp)),
			reverse);
		printf(">>>>>>>>>>>>>>>>>>\n");
		writelines(lineptr, nlines, directory);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
