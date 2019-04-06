#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'
#define SIN '1'
#define EXP '2'
#define POW '3'
#define YEAH 1
#define NOP 0

int getch(void);
void ungetch(int);
int issep(int c, int c1, int c2, int c3);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	/* sin, exp, pow */
	/* 要时刻考虑缓冲区 如果不带参数c, 那么在函数体中要定义c, 然后先getch(), 但是上面while中最后getch()的c海在那里. 如果先ungetch(), 貌似可以解决这个问题, 但是会出现很扯淡的结果... 无限循环? '*/
	if (issep(c,'s','i','n'))
		return SIN;
	if (issep(c,'e','x','p'))
		return EXP;
	if (issep(c,'p','o','w'))
		return POW;
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */
	i = 0;
	if (isdigit(c))		/* collec integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		/* 至于这里为什么用++i而不用i++, 是为了保证数字后面的那个字符要被'\0'覆盖掉吗? */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
int issep(int c, int c1, int c2, int c3)
{
	if (c == c1) {
		if ((c = getch()) == c2) {
			if ((c = getch()) == c3)
				return YEAH;
			ungetch(c);
		}
		ungetch(c);
	}
	return NOP;
}
