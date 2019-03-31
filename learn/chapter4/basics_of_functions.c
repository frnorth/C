#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for*/

/* find all lines matching pattern */
main()
{
	char line[MAXLINE];
	int found = 0;

	while (getline2(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

/* getline: get line into s, return length */
int getline2(char s[], int lim)
{
	int c, i;

	i = 0;

/*	或许用这个跟简洁一些. 而且注意这里要用--lim, 而不是lim--
*/	while (--lim  && (c = getchar()) != EOF) {
		s[i++] = c;
		if (c == '\n')
			break;
	}

/*	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;	
	if (c = '\n')
		s[i++] = c;
*/
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		/* 这里隐藏了一个逻辑, 当i比较靠近边界的时候, t长度已经比剩余的s长了, 
		 * 而, 循环中没有做额外的判断, 因为s[j] == t[k] 足够了, 
		 * 因为, s[j]到了边界是'\0', 自然会 != 未到边界的t[k], 使循环结束*/
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
