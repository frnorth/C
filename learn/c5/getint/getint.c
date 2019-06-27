#include <stdio.h>

int getch();
void ungetch(int);

int getint(int *p)
{
	int c, sign, tmp;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		tmp = c;
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			ungetch(tmp);
			return 0;
		}
	}
	for (*p = 0; isdigit(c); c = getch())
		*p = *p * 10 + c + 0 - '0';
	*p *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
