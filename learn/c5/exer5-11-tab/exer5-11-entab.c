#include <stdio.h>

#define TABSTOPS 8 
/* a second choise */
/*#define printtabs(x) { \
	for (; x > 0; x--) \
		printf("-"); \
}*/
#define printtabs(x) { \
	int i; \
	for (i = 0; i < x; i++) \
		printf("-"); \
}

main(int argc, char *argv[])
{
	int c, i = 0, j, nspace = 0, tabs;

	tabs = --argc > 0 ? atoi(*++argv) : TABSTOPS;
	printtabs(tabs);
	printf("\n");
	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
			++nspace;
			break;
		case '\n':
			putchar(c);
			i = 0;
			nspace = 0;
			break;
		default:
			for (; nspace > 0; nspace--)
				printf("#");
			putchar(c);
			break;
		}
		++i;
		if (i >= tabs) {
			//printf("\'%d\'", tabs);
			tabs = --argc > 0 ? atoi(*++argv) : TABSTOPS;
			if (nspace > 0)
			/* nspace contains the different space until next 'tabs' */
				printtabs(nspace);
			i = 0;
			nspace = 0;
		}
	}
}

