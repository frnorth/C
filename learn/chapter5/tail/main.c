#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define defparameter(x) { \
	if (isnum(++argv[0])) \
		x = atoi(argv[0]); \
	else { \
		printf("%s maybe wrong parameter\n", --argv[0]); \
		return -1; \
	} \
}

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
int isnum(char *s);

/* sort input lines */
main(int argc, char *argv[])
{
	int nlines, n = 10, i; /* number of input lines read */

	while (--argc > 0) {
		if (*(++argv)[0] == '-')
			defparameter(n)
		else {
			printf("%s maybe wrong parameter\n", argv[0]);
			return -1;
		}
	}
	
	if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
		printf("nlines: %d  n: %d >>>>>>>>>>>>>>>>>>\n", nlines, n);
		if (nlines <= n) 
			for (i = 0; nlines-- > 0; i++)
				printf("%s\n", lineptr[i]);
		else {
			for (i = 0; nlines > n; nlines--, i++)
				;
			for (; nlines-- > 0; i++)
				printf("%s\n", lineptr[i]);
		}		
		return 0;
	} else {
		printf("Error: input too big to be tail of\n");
		return 1;
	}
}
int isnum(char *s)
{
	while(isdigit(*s))
		s++;
	if(*s == '.')
		s++;
	while(isdigit(*s))
		s++;
	return (*s == '\0');
}
