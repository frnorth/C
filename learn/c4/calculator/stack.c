#include <stdio.h>
#define MAXVAL 100		/* maximum depth of val stack */

int sp = 0;				/* next free stack position */
double val[MAXVAL];		/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	int i;

	extern int bufp;
	printf("stack file print bufp: %d\n", bufp);

	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);

	printf("stack: ");
	for (i = 0; i < sp; i++)
		printf("%f ", val[i]);
	printf("\n");
}

/* pop: pop and return top value from stack */
double pop(void)
{
	//printf("yeah\n");
	if (sp > 0)
		/* 注意push后++, 所以pop先--*/
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* swap */
void swap(void)
{
	double tmp;

	if (sp > 0)
		printf("%g\n", val[sp - 1]);
	else {
		printf("error: stack empty\n");
	}
	tmp = val[sp - 1];
	val[sp - 1] = val[sp -2];
	val[sp - 2] = tmp;
}

void clear(void)
{

	while (sp > 0)
		val[--sp] = 0;
}
