#include <stdio.h>
#define BUFSIZE 100
#define EOFSTATE '5'

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

//int getch(void)		/* get a (possibly pushed back) character */
//{
//	return (bufp > 0) ? buf[--bufp] : getchar();
//}

/* handle the pushed-back EOF */
int getch(void)
{
	if (bufp > 0) {
		if (buf[--bufp] == EOF)
			return EOFSTATE;
		else
			return buf[bufp];
	}
	return getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
	printf("%d\t%d%c\t%d%c\n", bufp, buf[0],buf[0], buf[bufp - 1],buf[bufp - 1]);
}

/* where to use this function? */
void ungets(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		ungetch(s[i++]);
}
