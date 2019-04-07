#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VALUBLE '4'
#define YEAH 1
#define NOP 0

int getch(void);
void ungetch(int);
void ungets(char []);
int issep(int c, int c1, int c2, int c3);

/* getop: get next operator or numeric operand */
int getop(char s[])
{

	//ungets("123");

	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	/* sin, exp, pow */
	/* 要时刻考虑缓冲区 如果不带参数c, 那么在函数体中要定义c, 然后先getch(), 但是上面while中最后getch()的c海在那里. 如果先ungetch(), 貌似可以解决这个问题, 但是会出现很扯淡的结果... 无限循环? */
	if (issep(c,'s','i','n'))
		return SIN;
	if (issep(c,'e','x','p'))
		return EXP;
	if (issep(c,'p','o','w'))
		return POW;

	/* a very big problem, if input: '1' --- 'k' --- 'ctrl +d', 停止本次输入, 然而会hang住, 再ctrl + d, 会返回valuble, 就是说第二次的ctrl + d是让getop()了一个EOF */
	while (islower(c) || isupper(c)) {
		s[++i] = c = getch();
		s[i] = '\0';
		/*  如果名字val 后面跟了个1, 那么, 如果没有下面的判断, 1就不会被放回到input中 */
		if (c != EOF && c != '\n')
			ungetch(c);
		return VALUBLE;
	}

	/* is s[] digit? */
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */

	/* get the number */
	i = 0;
	//if (isdigit(c))		/* collec integer part */
	//	/* 为什么++i, ++放在前面? */
	//	while (isdigit(s[++i] = c = getch()))
	//		;
	/* why not like this? */
	while (isdigit(c))
		s[++i] = c = getch();

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
