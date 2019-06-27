#include <stdio.h>
#include <stdlib.h>

#define TABSTOPS 8
#define defprint(x) printf(#x ": %d\n", x)
#define defparameter(x) { \
	if (isnum(++argv[0])) \
		x = atoi(argv[0]); \
	else { \
		printf("%s maybe wrong parameter\n", --argv[0]); \
		return -1; \
	} \
}

int isnum(char *s);
main(int argc, char *argv[])
{
	int c, i, clum, tabs;
	int n = 8, m = 0;

	while (--argc > 0) {
		c = *(++argv)[0];
		switch (c) {
		case '-':
			/* is that right to define marco like this? */
			defparameter(n);
			break;
		case '+':
			defparameter(m);
			break;
		default:
			printf("%s maybe wrong parameter\n", argv[0]);
			return -1;
			break;
		}
	}
	defprint(n);
	defprint(m);

	clum = 0;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '\t':
			if (clum >= m) {
				for (i = (clum - m) % n; i < n; i++)
					putchar('#');
				clum = clum + n - (clum - m) % n;
			}
			else {
				putchar(c);
				clum = clum + TABSTOPS - clum % TABSTOPS;
			}
			break;
		case '\n':
			clum = 0;
			putchar(c);
			break;
		default:
			putchar(c);
			clum++;
			break;
		}
	}
}

int isnum(char *s)
{
	while(isdigit(*s))
		s++;
	if(*s == '.')
		s++;
	while(isdigit(*s))
		s++;
	return (*s == '\0');
}
