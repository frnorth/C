#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);
void copy(char to[], char from[]);
void reblantabs(char line[], int len);

/* print longest input line */
main() {
	int len; /* current line length */
	int max; /* maximum length seen so far */
	int alllen;
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */

	max = 0;
	alllen = 0;
	while ((len = getline2(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
		reblantabs(line, len);
		printf("length of this line is: %d\n", len);
		printf("line after remove trailing blanks is: %s\n", line);
		alllen = alllen + len;
	}

	printf("whole length of the text is: %d\n", alllen);
	if (max > 0) /* there was a line */
		printf("length of the longest line is: %s", longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;

	//to[i] = 'h';
}

/* remove ttailing blanks and tabs */
void reblantabs(char line[], int len) {
	//这里牛逼的地方在于, 清楚的知晓了geline2在结尾的时候的情况, 并且对结尾是否为'\n'进行了分类讨论。
	int lastone;
	if (line[len-1] == '\n')
		lastone = 2;
	else 
		lastone = 1;
	while ((line[len - lastone] == ' ') || (line[len - lastone] == '\t')) {
		line[len - lastone] = 'h';
		--len;
	}
}
