#include <stdio.h>

char buf;	/* buffer for ungetch */
int bufstate = 0;		/* next free position in buf */

int getch(void)		/* get a (possibly pushed back) character */
{
	if (bufstate > 0) {
		bufstate = 0;
		return buf;
	}
	else
		return getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if (bufstate > 0)
		printf("ungetch: too many characters\n");
	else {
		buf = c;
		bufstate = 1;
	}
	printf("%d %c\n", bufstate, buf);
}

/* where to use this function? */
void ungets(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		ungetch(s[i++]);
}
