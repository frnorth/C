#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'

/* getop: get next operator or numeric operand */
int getop(char line[], char s[])
{

	//ungets("123");
	printf("getop\n");

	int i, j, c;
	
	i = 0;
	j = 0;

	while ((s[0] = c = line[i++]) == ' ' || c == '\t') 
		;
	printf("in: %s\n",line);
	//printf("%d\t%d\t%c  %d\n",i, c, c, '\0');
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		line[i - 1] = ' ';
		//printf("\t%d\n", c);
		return c;
	}
	if (isdigit(c))
		while (isdigit(s[++j] = c = line[i++]))
			line[i - 2] = ' ';
	if (c == '.')
		while (isdigit(s[++j] = c = line[i++]))
			line[i - 2] = ' ';
	line[i - 2] = ' ';
	s[j] = '\0';
	//printf("%s\n", s);
	return NUMBER;
}
