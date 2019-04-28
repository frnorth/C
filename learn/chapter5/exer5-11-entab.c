#include <stdio.h>

#define TABSTOP 8 

main(int argc, char *argv)
{
	int c, i, j, nspace, tabs;

	tabs = argc > 1 ? atoi(*(argv + 1)) : TABSTOPS;
	i = 0;
	nspace = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nspace;
		else {
			for (j = 0; j < nspace; ++j)
				printf("#");
			putchar(c);
			nspace = 0;
		}
		++i;
		if (i >= tabs || c == '\n') {
			tabs = argc > 1 ? atoi(*(argv + 1)) : TABSTOPS;
			if (nspace > 0)
				printf("\t");
			i = 0;
			nspace = 0;
		}
	}
}

