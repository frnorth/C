#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 9

struct key {
	char *word;
	int count;
} keyword[] = {
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

int getword(char *, int);
int binsearch(char *, struct key *, int);

main()
{
	int n;
	char word[MAXWORD];

	
}

int getword(char *s, int maxlength)
{
	char c;
	int i;

	for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}

