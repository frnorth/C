#include <stdio.h>
#define BUFSIZE 100
//#define EOFSTATE '5'
#define EOFSTATE EOF

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

//int getch(void)		/* get a (possibly pushed back) character */
//{
//	return (bufp > 0) ? buf[--bufp] : getchar();
//}

/* handle the pushed-back EOF */
int getch(void)
{	
	int c;

	//printf("\t--> getch: ");
	//for (i = 0; i < bufp; i ++)
	//	printf("%d %c(%d)\t", i, buf[i], buf[i]);
	//printf("\n");

	if (bufp > 0) {
		if (buf[--bufp] == EOF) {
			printf("\t--> \033[33mgetch\033[0m: buf%d %c(%d)\n", bufp, buf[bufp], buf[bufp]);
			return EOFSTATE;
		}
		else {
			printf("\t--> \033[33mgetch\033[0m: buf%d %c(%d)\n", bufp, buf[bufp], buf[bufp]);
			//printf("\t--> getch: buf%d %c(%d)\n", bufp, buf[bufp], buf[bufp]);
			return buf[bufp];
		}
	}
	c = getchar();
	printf("\t--> \033[33mgetch\033[0m: %c(%d)\n", c, c);
	return c;
}

void ungetch(int c)	/* push character back on input */
{
	int i;

	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

	printf("\t--> \033[36mungetch\033[0m: ");
	for (i = 0; i < bufp; i ++)
		printf("%d %c(%d)\t", i, buf[i], buf[i]);
	printf("\n");
}

/* where to use this function? */
void ungets(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		ungetch(s[i++]);
}
