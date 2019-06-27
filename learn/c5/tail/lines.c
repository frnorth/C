#include <stdio.h>
#include <string.h>
#define MAXLEN 1000 /* max length of any inpot lines */
int getline2(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline2(line, MAXLEN)) > 0)
		if (nlines > maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0'; /* delete newline */
			strcpy(p, line);
			printf("nlines %d: %s\n", nlines, p);
			lineptr[nlines++] = p;
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
