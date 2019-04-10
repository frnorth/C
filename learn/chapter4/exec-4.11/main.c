#include <stdio.h>
#include <stdlib.h>		/* for atof() */
#include <math.h>

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void swap(void);
//double sin(double);

/* reverse Polish calculator */
main()
{
	int type, count=0;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
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
			printf("\t%.8g\n", pop());
			//swap();
			clear();
			break;
		default:
			printf("error: unknow command %s\n", s);
			break;
		}
	}
	return 0;
}


