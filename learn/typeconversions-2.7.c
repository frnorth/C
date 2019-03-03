#include <stdio.h>

#define MAXLINE 30

int atoi(char s[]);
int lower(int c);

main() {
	int num;
	char s[MAXLINE];

	getline2(s, MAXLINE);
	num = atoi(s);
	
	printf("\n%s %d\n", s, num);
}

getline2(char s[], int limit) {
	int c, i;

	for (i = 0; i < limit - 1; ++i) {
		c = getchar();
		if (c == '\n')
			i += limit;
		else if (c == EOF)
			i += limit;
		else {
			//c = lower(c);
			c = tolower(c);
			s[i] = c;
		}
	}

	if (i > limit - 1)
		i = i - limit + 1;
	s[i] = '\0';
}

/* atoi: convert s to integer */
int atoi(char s[]) {
	int i, n;

	n = 0;
	for (i = 0; /* s[i] >= '0' && s[i] <= '9' */ isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
	if (c >= 'A' && c <= 'Z')
		return  c + 'a' - 'A';
	else
		return c;
}
