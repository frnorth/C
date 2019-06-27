#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tnode.h"

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c == EOF) {
		*w = '\0';
		return c;
	}
	*w++ = c;
	for (; --lim > 0; w++)
		if (isspace(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	defprint(s, word);
	return word[0];
}

