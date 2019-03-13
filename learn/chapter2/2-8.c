#include <stdio.h>
#include <math.h>

#define MAXLINE 30

void getline2(char s[], int lim);
void getline3(char s[], int limit);
void squeeze(char s[], int c);

main() {
	int num, i;
	char s[MAXLINE];

	getline3(s, MAXLINE);
	squeeze(s, 'c');
	printf("%s\n", s);

}

/* a fun problem has happen! */
void getline3(char s[], int limit) {
	int c, i;

	for (i = 0; i < limit - 1; ++i) {
		c = getchar();
		if (c == '\n') {
			s[i] = '\n';
			i += limit;
		}
		else if (c == EOF)
			i += (limit - 1);
		else {
			//c = lower(c);
			//c = tolower(c);
			s[i] = c;
		}
	}

	if (i > limit - 1)
		i = i - limit + 1;
	s[i] = '\0';
}

/* squeeze: delete all c from s[] */
void squeeze(char s[], int c) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c) {
			s[j++] = s[i];
			printf("%c\n", s[j-1]);
		}
	s[j] = '\0';
}

/* getline2: read a line into s, return length */
void getline2(char s[], int lim) {
	int c, i;

	/* 这里, 当到达998的时候会出现几种情况? 和书后面说的, By testing the length and the last character returned, main can determine whether the line was too long, and then cope as it wishes. 怎么对应上???*/
	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	/* 这里好像有点牛逼, 如果什么都不输入直接ctrl+d, 那么s[]还是有值的s[0]='\0', 但是i=0, return 0, len=0, 那么长度还是0, 所以最终没有输出, 巧妙地用了0开头这个事实。*/
	s[i] = '\0';
}

void stract2(char s[], char t[]) {
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
}
