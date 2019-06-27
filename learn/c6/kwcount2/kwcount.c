#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "keytab.h"

#define MAXWORD 100
#define defprint(type, x) printf(#x ": %" #type"\n", x)

int getword(char *, int);
struct key *
binsearch(char *, struct key *, int);

main()
{
	char word[MAXWORD];
	struct key *p;

	defprint(d, NKEYS);

	while (getword(word, MAXWORD) != EOF) {
		defprint(s, word);
		if(isalpha(word[0]))
			/* if one tab a + (upcursor), and != NULL not here, the segmentation fault would be happen */
			if((p =  binsearch(word, keytab, NKEYS)) != NULL) {
				defprint(s, p->word);
				p->count++;
			}
	}
	for (p = keytab; p < keytab + NKEYS; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
}

struct key *
binsearch(char *word, struct key *tab, int n)
{
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;

	/* note that the high pointer is outside the tab[] one index more, as &tab[n], and while(statement) is low < high, and high = mid, not mid + 1 any more!! */
	while (low < high) {
		mid = low + (high - low)/2;
		defprint(d, mid - low);
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
