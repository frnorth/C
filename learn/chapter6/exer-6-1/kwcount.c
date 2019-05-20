#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define defprint(type, x) printf(#x ": %" #type"\n", x)

struct key {
	char *word;
	int count;
} keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"char", 0},
	{"double", 0},
	{"else", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"unsigned", 0},
	{"while", 0}
};

//#define NKEYS (sizeof keytab / sizeof(struct key))
#define NKEYS (sizeof keytab / sizeof keytab[0])

int getword(char *, int);
int binsearch(char *, struct key *, int);

main()
{
	int n;
	char word[MAXWORD];

	defprint(d, NKEYS);

	while (getword(word, MAXWORD) != EOF) {
		defprint(s, word);
		if(isalpha(word[0]))
			if((n = binsearch(word, keytab, NKEYS)) >= 0) {
				defprint(d, n);
				keytab[n].count++;
			}
	}
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
}

int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high)/2;
		defprint(d, mid);
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	/* exer-6-1 ignore the comments */
	if (c == '/') {
		if ((c = getch()) == '*') {
			while ((c = getch()) != EOF) {
				if (c  == '*' && (c = getch()) == '/') {
 					/* if not do like this, the c will be '/' as the end of the comments, that will be signed to *w++, and w will got a '/' as a single word. if the tab[] list contains '/', the w here will be miscompared */
					while (isspace(c = getch()))
						;
					break;
				}
			}
		} else
			*w++='/';
	}
	/*------------------------------*/
	if (c != EOF)
		*w++ = c;
	/* exer-6-1 handle underscores words */
	if (!(isalpha(c) || c == '_')) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		/* exer-6-1 handle underscores words */
		if (!(isalnum(*w = getch()) || *w == '_')) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
