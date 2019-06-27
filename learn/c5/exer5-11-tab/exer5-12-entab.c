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
#define printtabs(x) { \
	int i; \
	for (i = 0; i < x; i++) \
		printf("-"); \
}

int isnum(char *s);
main(int argc, char *argv[])
{
	int c, i = 0, im = 0, nspace = 0;;
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

	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
			++nspace;
			break;
		case '\n':
			putchar(c);
			i = 0;
			im = -1;
			nspace = 0;
			break;
		default:
			for (; nspace > 0; nspace--)
				printf("#");
			putchar(c);
			break;
		}
		++i;
		++im;
		if (im == m) {
			for (; nspace > 0; nspace--)
				printf("#");
			i = 0;
		}
		if (im > m && i >= n) {
			if (nspace > 0)
			/* nspace contains the different space until next 'tabs' */
				printtabs(nspace);
			i = 0;
			nspace = 0;
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
