#include <stdio.h>
#include <stdlib.h>

#define TABSTOPS 8
#define defprint(x) printf(#x ": %d\n", x)

main(int argc, char *argv[])
{
	int c, i, tabs;

	tabs = argc > 1 ? atoi(*(argv + 1)) : TABSTOPS;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			//defprint(tabs);
			tabs = --argc > 0 ? atoi(*++argv) : TABSTOPS;
			for(; i < tabs; ++i)
				printf("#");
		}
		else {
			putchar(c);
			++i;
		}
		if (i >= tabs || c == '\n')
			i = 0;
	}
}
