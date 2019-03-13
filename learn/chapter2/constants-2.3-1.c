#include <stdio.h>

#define MAXLINE 1000
int strlen2(char s[]);

main() {
	int i;
	char s[MAXLINE];

	i = 0;
	while (((s[i] = getchar()) != EOF) && (i < MAXLINE - 1))
		++i;
	s[i] = '\0';

	printf("%d\n",strlen2(s));
	printf("%d\n",strlen2("haha"));

	
}


int strlen2(char s[]) {
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}
