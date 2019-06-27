#include <stdio.h>

main() {
	int c, nspace, ntab, nline;

	nspace = 0;
	ntab = 0;
	nline = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nspace;
		if (c == '\t')
			++ntab;
		if (c == '\n')
			++nline;
	}

	printf("space number is %d\n", nspace);
	printf("tab number is %d\n", ntab);
	printf("line number is %d\n", nline);
}
