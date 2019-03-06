#include <stdio.h>
#include <math.h>

#define MAXLINE 30

void getline3(char s[], int limit);
void squeeze(char s1[], char s2[]);

main() {
	int num, i;
	char s1[MAXLINE];
	char s2[MAXLINE];

	getline3(s1, MAXLINE);
	getline3(s2, MAXLINE);

	squeeze(s1, s2);

	printf("%s\n", s1);

}

void getline3(char s[], int limit) {
	int c, i;

	for (i = 0; i < limit - 1; ++i) {
		c = getchar();
		if (c == '\n') {
			s[i] = c;
			i += limit;
		}
		else if (c == EOF)
			i += limit;
		else {
			c = tolower(c);
			s[i] = c;
		}
	}

	if (i > limit - 1)
		i = i - limit + 1;
	s[i] = '\0';
}

void squeeze(char s1[], char s2[]) {
	int i, j, k;

	for(i = j = 0; s1[i] != '\0'; i++) {
		for(k = 0; (s2[k] != '\0') && (s1[i] != s2[k]); k++)
			;
		if (s2[k] == '\0')
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
