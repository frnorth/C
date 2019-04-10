#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100
#define NUMBER '0'

int getch(char buf[], int bufp[]);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, j;
	static char buf[BUFSIZE];
	/* 如果只是bufp, 传参到getch()中, 其值不会被改变, 除非用&, 可那是后话了. */
	static int bufp[1];
	bufp[0] = 0;

	while ((s[0] = c = getch(buf, bufp)) == ' ' || c == '\t')
		;
	s[1] = '\0';

	/* is s[] digit? */
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */

	i = 0;
	/* get the number */
	while (isdigit(c))
		s[++i] = c = getch(buf, bufp);
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch(buf, bufp)))
			;
	s[i] = '\0';

	if (bufp[0] >= BUFSIZE)
		printf("to many bufs\n");
	else
		buf[bufp[0]++] = c;
	for (j = 0; j < bufp[0]; j++)
		printf("%d %d %c\t", j, buf[j], buf[j]);
	printf("\n");

	return NUMBER;
}

int getch(char buf[], int bufp[])		/* get a (possibly pushed back) character */
{
	return (bufp[0] > 0) ? buf[--bufp[0]] : getchar();
}
