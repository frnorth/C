#include <stdio.h>

#define MAXCOLLUM 30
#define MAXWORD 30
#define TABSTOP 8

main() {
	int c, i, linelen, overstap;
	char word[MAXWORD];

	i = 0;
	linelen = 0;
	overstap = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			if (i < MAXWORD) {
				word[i] = c;
				++i;
				++linelen;
			}
			if (i >= MAXWORD)
				overstap = 1;
		}
		else {
			word[i] = '\0';
			if (linelen <= MAXCOLLUM)
				printf("%s%c", word, c);
			else {
				printf("\n%s%c", word, c);
				linelen = 0;
			}
			i = 0;
			if (c == ' ')
				++linelen;
			if (c == '\t')
				linelen += (8-(linelen % 8));
		}
	}
	if (overstap == 1)
		printf("there was a word has words too many\n");
}
