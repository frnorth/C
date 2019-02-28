#include <stdio.h>

#define TABSTOP 8
#define MAXLINE 1000

int getline2(char line[], int maxline);
void entab(char line[], int len);

main() {
	int len;
	char line[MAXLINE];

	while ((getline2(line, MAXLINE)) > 0)
		entab(line[], len);
}

int getline2(char line[], int maxline) {
	int c, i;

	for (i = 0; (i< maxline-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';

	return i;
}

void entab(char line[], int len) {
	int i, j;

	for (i = 0; i < len; i+=TABSTOP) {
		if ()
		for (j = 0; j < TABSTOP; ++j) {
			
		}
	}

}
