#include <stdio.h>

#define TABSTOP 8 

void detab(int tabstop);
void entab(int tabstop);

main() {

	//detab(TABSTOP);
	entab(TABSTOP);
}
/* ex1-20 */
void detab(int tabstop) {
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			for(; i < tabstop; ++i)
				printf("#");
		else {
			putchar(c);
			++i;
		}
		if (i >= tabstop || c == '\n')
			i = 0;
	}
}

/* ex1-21*/
void entab(int tabstop) {
	int c, i, j, nspace;

	i = 0;
	nspace = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (nspace == 0)
				nspace = 1;
			else
				++nspace;
		}
		else /*if (c != '\n') 这个不加更有道理?*/ {
			for (j = 0; j < nspace; ++j)
				printf("#");
			putchar(c);
			nspace = 0;
		}
		++i;
		if (i >= tabstop || c == '\n') {
			if (nspace > 0){
				printf("\t");
			}
			i = 0;
			nspace = 0;
		}
	}
}

