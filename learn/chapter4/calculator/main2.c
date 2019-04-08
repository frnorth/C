#include <stdio.h>
#include <stdlib.h>		/* for atof() */
#include <math.h>

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
int getop(char line[], char s[]);
void push(double);
double pop(void);
void clear(void);
void swap(void);
//double sin(double);

/* reverse Polish calculator */
main()
{
	int type, len, count = 0;
	double op2;
	char s[MAXOP];
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0) {
		//printf("%s\n",line);
		/* 让getop 直接将line已经读过的内容清空, 这样来记录line的位置 */
		while ((type = getop(line, s)) != EOF) {
			printf("line: %s\n",line);
			//if (count > 5)
			//	break;
			//printf("%d\n", count);
			//count++;
			switch (type) {
			case NUMBER:
				printf("%s\n", s);
				push(atof(s));
				break;
			case '+':
				//printf("2\n");
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 > 1.0)
					push((double)((int)pop() % (int)op2));
				else
					printf("error: zero moduluer\n");
				break;
			case '\n':
				printf("result is \t%.8g\n", pop());
				clear();
				break;
			case '\0':
				printf("\\0, goto the goon\n");
				goto goon;
			default:
				printf("error: unknow command %s\n", s);
				break;
			}
		}
goon:
		printf("getop over\n");
	}
	return 0;
}


