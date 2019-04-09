#include <stdio.h>
#include <stdlib.h>		/* for atof() */
#include <math.h>
#include "calc.h"

#define MAXOP 100		/* max size of operand or operator */

/* reverse Polish calculator */
main()
{
	int type, count=0;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
	//while ((type = getop(s))) {
		//if(count > 10)
		//	break;
		//count++;
		//printf("%c\n", type);
		switch (type) {
		//case EOF:
		//	printf("the EOF ");
		//	break;
		case EOFSTATE:
			printf("the pushed back EOF here\n");
			break;
		case NUMBER:
			//printf("%f\n",atof(s));
			push(atof(s));
			break;
		case SIN:
			//printf("sin, %f", sin(30.2));
			/* 3.1415926 * 2 == 360度 */
			push(sin(pop()));
			break;
		case EXP:
			push(exp(pop()));
			break;
		case POW:
			op2 = pop();
			push(pow(pop(),op2));
			break;
		case VALUBLE:
			printf("\t%s: %.8g\n",s , pop());
			clear();
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


