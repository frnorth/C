#include <stdio.h>
#include <math.h>

#define defprint(x) printf(#x ": %f\n", x)

int getch();
void ungetch(int);

int getfloat(double *p)
{
	int c, sign, tmp;

	while (isspace(c = getch()))
		;
	/* if you want to recognize .12 as 0.12 correctly, an additional statement should be attached */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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
	if (c == '.') {
		tmp = c;
		c = getch();
		defprint(c);
		if (!isdigit(c)) {
			ungetch(c);
			ungetch(tmp);
			/* if not adding this, input of "-12. 22" would ouput "12 0 0 ...", where is the '-'? */
			*p *= sign;
			return 0;
		}
		for (tmp = 1; isdigit(c); c = getch(), tmp++) {
			defprint(*p);
			*p = *p + ((double)(c + 0 - '0')) / ((double)pow(10, tmp));
		}
	}
	*p *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
