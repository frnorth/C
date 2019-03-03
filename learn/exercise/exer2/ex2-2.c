#include <stdio.h>

#define MAXLINE 30

main() {
	int c, i;
	char s[MAXLINE];

	for (i = 0; i < MAXLINE - 1; ++i) {
		c = getchar();
		if (c == '\n')
			i += MAXLINE;
		else if (c == EOF)
			i += MAXLINE;
		else
			s[i] = c;
	}

	printf("\n%s\n", s);
}
