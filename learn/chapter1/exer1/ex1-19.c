#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);
void reverse(char to[], char from[], int len);

/* print reverseline input line */
main() {
	int len, i; /* current line length */
	char line[MAXLINE]; /* current input line */
	char reverseline[MAXLINE]; /* reverseline line saved here */

	while ((len = getline2(line, MAXLINE)) > 0) {
		reverse(reverseline, line, len);
		printf("%s\n", reverseline);
		for (i = 0; i < MAXLINE; ++i)
			reverseline[i] = '\0';
	}

	return 0;
}

/* getline2: read a line into s, return length */
int getline2(char s[], int lim) {
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
	return i;
}

/* reverse, 然而如果只能由一个参数reverse(s), 要怎么做呢? */
void reverse(char to[], char from[], int len) {
	int i, lastone;

	i = 0;
	if (from[len-1] == '\n')
		lastone = 2;
	else 
		lastone = 1;

	while (i < len) {
		to[i] = from[len - lastone - i];
		++i;
	}
	//to[i] = 'h';
}
