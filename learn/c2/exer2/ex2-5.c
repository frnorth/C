#include <stdio.h>
#include <math.h>

#define MAXLINE 30

void getline3(char s[], int limit);
int any(char s1[], char s2[]);

main() {
	int position;
	char s1[MAXLINE];
	char s2[MAXLINE];

	getline3(s1, MAXLINE);
	getline3(s2, MAXLINE);

	position = any(s1, s2);

	printf("%d\n", position);

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

int any(char s1[], char s2[]) {
	int i, k;

	for(i = 0; s1[i] != '\0'; i++) {
		for(k = 0; (s2[k] != '\0') && (s1[i] != s2[k]); k++)
			;
		if (s2[k] != '\0')
			s1[i+1] = '\0';
	}
	return i;
}
