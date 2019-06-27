#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tnode.h"

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '/') {
		if ((c = getch()) == '*') {
			while ((c = getch()) != EOF)
				if (c  == '*' && (c = getch()) == '/')
					break;
		} else
			*w++='/';
	}
	if (c == '"') {
		while ((c = getch()) != EOF)
			if (c  == '"')
				break;
	}
	if (c != EOF)
		*w++ = c;
	if (!(isalpha(c) || c == '_' || c == '#')) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!(isalnum(*w = getch()) || *w == '_' || *w == '#')) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
