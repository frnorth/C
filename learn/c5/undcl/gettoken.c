#include <stdio.h>
#include <string.h>
#include "declar.h"

int gettoken(void)
{
	printf("-------gettoken\n");

	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)){
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

/* exer 5-19 */
void ungettoken()
{
	char *p = token;
	void ungetch(int);

	for (; *p != '\0'; p++)
		;
	while (--p >= token)
		ungetch(*p);
}
