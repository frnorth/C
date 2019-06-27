#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"


/* getop: get next operator or numeric operand */
int getop(char *s)
{

	//ungets("123");

	int i, c;
	char *s0 = s;

	while ((*s = c = getch()) == ' ' || c == '\t')
		;
	*++s = '\0';

	/* handle the pushed-back EOF */
	if (c == EOFSTATE)
		return EOFSTATE;

	/* sin, exp, pow */
	if (issep(c,'s','i','n'))
		return SIN;
	if (issep(c,'e','x','p'))
		return EXP;
	if (issep(c,'p','o','w'))
		return POW;

	s = s0;
	if (islower(c) || isupper(c)) {
		while (islower(c) || isupper(c) || isdigit(c))
			*++s = c = getch();
		*s = '\0';
		if (c != EOF && c != '\n')
			ungetch(c);
		return VALUBLE;
	}

	/* is s[] digit? */
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */

	while (isdigit(c))
		*++s = c = getch();

	if (c == '.')		/* collect fraction part */
		while (isdigit(*++s = c = getch()))
			;
	*s = '\0';
	//if (c != EOF)
		ungetch(c);
	return NUMBER;
}
int issep(int c, int c1, int c2, int c3)
{
	int tmp;

	if (c == c1) {
		if ((tmp = c = getch()) == c2) {
			//tmp = c;
			if ((c = getch()) == c3)
				return YEAH;
			ungetch(c);
		}
		ungetch(tmp);
	}
	return NOP;
}
