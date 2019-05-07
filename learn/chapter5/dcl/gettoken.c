#include <stdio.h>
#include <string.h>
#include "declar.h"

void ungetch(int);
//#define defprint(x) printf("-------return " #x ": %d\n", x)
#define defprint(x, y) printf("-------\033[33mreturn\033[0m " #x " %s\n", y)
int gettoken(void)
{
	printf("-------gettoken\n");

	int c, getch(void);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			defprint(PARENS, token);
			return tokentype = PARENS;
		} else {
			ungetch(c);
			defprint('(', NULL);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		defprint(BRACKETS, token);
		return tokentype = BRACKETS;
	} else if (isalpha(c)){
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		defprint(NAME, token);
		return tokentype = NAME;
	} else {
		defprint(c, &c);
		return tokentype = c;
	}
}

/* this is fot exer 5-20 */
void ungettoken()
{
	char *p0, *p;

	if (tokentype == NAME || tokentype == PARENS || tokentype == BRACKETS) {
		p0 = p = token;
		for (; *p != '\0'; p++)
			;
		while (--p >= p0)
			ungetch(*p);
	}
	else
		ungetch(tokentype);
}

/* this is also fot exer 5-20 */
// this is a very elaborate and amazing type casting, when calling the ungettoken function!! -- ungettoken((char *)&type);
void ungettoken2(char *p)
{
	char *p0 = p;

	for (; *p != '\0'; p++)
		;
	while (--p >= p0)
		ungetch(*p);
}
