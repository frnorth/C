#include <stdio.h>
#include <string.h>

#define MAXLEN 100
#define MAXLINES 100

#define defprint(x) printf(#x ": %d\n", x)
#define defprints(x) printf(#x ": %s\n", x)

#define PAR(var, c1, c2) { \
	if (*(*a) == '-' && *(*a + 1) == c1 && *(*a + 2) == c2) { \
		defprints(*a); \
		defprints(*a + 1); \
		defprints(*a + 2); \
		var = 1; \
	} \
}

int getline2(char *s, int lim);

main(int argc, char *argv[])
{
	char line[MAXLINES][MAXLEN];
	char *lineptr[MAXLINES], **a = argv;
	char *l = line[0], **lptr0, **lptr = lineptr;
	int x = 0, n = 0, num = argc;

	//defprint(*a);
	//defprint(*a + 1);
	//defprint(*(a + 1));
	//defprint(*(a + 1) + 1);
	//defprint(++*a);
	//defprint(*++a);

	for (; num-- > 0; a++) {
		//if (*(*a) == '-' && *++(*a) == 'x')
		//if (*(*a) == '-' && *(*a + 1) == 'x')
		//	x = 1;
		//if (*(*a) == '-' && *(*a + 1) == 'n')
		//	n = 1;
		PAR(x, 'x', '\0');
		PAR(n, 'n', '\0');
		PAR(x, 'n', 'x');
		PAR(n, 'x', 'n');
		PAR(x, 'x', 'n');
		PAR(n, 'n', 'x');
	}

	//defprints(*++a);
	defprint(x);
	defprint(n);

	//defprints(*a);
	for (a--; getline2(l, MAXLEN) > 0; l += MAXLEN)
		if ((x == 0 && strstr(l, *a) != NULL) || (x == 1 && strstr(l, *a) == NULL))
			*lptr++ = l;

	printf("Result is: \n");
	for (lptr0 = lineptr; lptr0 < lptr ; lptr0++) {
		//if (n > 0)
		//	printf("%d %s", (*lptr0 - line[0])/MAXLEN + 1, *lptr0);
		//else
		//	printf("%s", *lptr0);
		if (n > 0)
			printf("%d ", (*lptr0 - line[0])/MAXLEN + 1);
		printf("%s", *lptr0);
	}
	return 0;
}
