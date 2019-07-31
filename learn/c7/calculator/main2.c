#include <stdio.h>
#include <string.h>
#include <stdlib.h>		/* for atof() */
#include <math.h>

#define defprint(type, x) printf(#x ": \033[33m%" #type "\033[0m\n", x)

#define MAXLINE 1000
#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VALUBLE '4'
#define EOFSTATE '5'
#define YEAH 1
#define NOP 0

int getline2(char s[], int lim);
void push(double);
double pop(void);
void clear(void);
void swap(void);
//double sin(double);
int isnum(char *s);

/* reverse Polish calculator */
main()
{
	int type, len, count;
	double op2;
	char s[MAXOP];
	char line[MAXLINE], *p;

	//printf("%d\n", len = getline2(line, MAXLINE));
	/* 与 lua 大不相同, (len = getline2(xxx,xxx)) 这个括号的值是len */
	while ((len = getline2(line, MAXLINE)) > 0) {
		for (p = line; isspace(*p); p++)
			;
		//printf("line: %sstrlen(line): %d\n*p: %d\nlen: %d\n\n", line, strlen(line), *p, len);
		while (sscanf(p, "%s", s) > 0) {
			p += strlen(s);
			for (; isspace(*p); p++)
				;
			//printf("s: %s\nstrlen(s): %d\n*p: %c\n\n", s, strlen(s), *p);

			//defprint(d, isnum(s));
			if (isnum(s)) {
				//printf("number\n");
				//defprint(s, s);
				push(atof(s));

			/* 注意 strcmp 两个字符串相等, 结果是 0 !! */
			} else if (strcmp("+", s) == 0) {
				//printf("+++\n");
				//defprint(s, s);
				push(pop() + pop());

			} else if (strcmp("-", s) == 0) {
				//printf("---\n");
				//defprint(s, s);
				op2 = pop();
				push(pop() - op2);

			} else if (strcmp("*", s) == 0) {
				//printf("***\n");
				//defprint(s, s);
				push(pop() * pop());

			} else if (strcmp("/", s) == 0) {
				//printf("///\n");
				//defprint(s, s);
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");

			} else if (strcmp("%", s) == 0) {
				//printf("+++\n");
				//defprint(s, s);
				op2 = pop();
				if (op2 > 1.0)
					push((double)((int)pop() % (int)op2));
				else
					printf("error: zero moduluer\n");

			} else {
				printf("error: unknow command %s\n", s);
			}

		}
		printf("\033[36mresult is \t%.8g\033[0m\n", pop());
		clear();
		printf("scanf over\n");
	}
	return 0;
}

int isnum(char *s)
{
	while(isdigit(*s))
		s++;
	if(*s == '.')
		s++;
	while(isdigit(*s))
		s++;
	return (*s == '\0');
}
