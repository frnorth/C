#include <stdio.h>
#include <string.h>
#define MAXLEN 1000 /* max length of any inpot lines */
int getline2(char *, int);
char *alloc(int);
int isdirectory(char *);

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
			printf("%s %d\n", p, nlines);
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

void writelines(char *lineptr[], int nlines, int directory)
{
	if (directory > 0) {
		while (nlines--) {
			if (isdirectory(*lineptr) > 0)
				printf("%s\n", *lineptr);
			lineptr++;
		}
	}
	else
		while (nlines--)
			printf("%s\n", *lineptr++);
}

int isdirectory(char *s)
{
	for (; isdigit(*s) || isupper(*s) || islower(*s) || isspace(*s); s++)
		;
	if (*s == '\0')
		return 1;
	return 0;
}
