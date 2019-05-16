#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
	char *word;
	int count;
} keytab[] = {
	("auto", 0),
	("break", 0),
	("char", 0),
	("double", 0),
	("else", 0),
	("goto", 0),
	("if", 0),
	("unsigned", 0),
	("while", 0)
}

//#define NKEYS (sizeof keytab / sizeof(struct key))
#define NKEYS (sizeof keytab / sizeof keytab[0])

int getword(char *, int);
int binsearch(char *, struct key *, int);

main()
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
			if(n = binsearch(word, keytab, NKEYS) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n] > 0)
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
		if (cond = strcmp(word, tab[middle].word) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


