#include <stdio.h>
#include <string.h>
#define MAXLEN 1000 /* max length of any inpot lines */
int getline2(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *array, int maxlen)
{
	int len, nlines;
	char *a0 = array, line[MAXLEN];

	nlines = 0;
	while ((len = getline2(line, MAXLEN)) > 0)
		/*                                      > or >= ?? */
		if (nlines > maxlines || array + len - a0 >= maxlen)
			return -1;
		else {
			/* len - 1 = '\0' would wrapped out the last character if getline2 end up by EOF ! */
			line[len - 1] = '\0'; /* delete newline */
			strcpy(array, line);
			//printf("%s %d\n", array, nlines);
			/* if it is for len - 1, array += len is right */
			array += len;
			lineptr[nlines++] = array;
		}
	return nlines;
}

void writelines2(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines--)
		printf("%s\n", *lineptr++);
}
