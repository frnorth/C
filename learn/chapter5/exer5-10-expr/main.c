#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(double f);
double pop(void);

main(int argc, char *argv[])
{
	double p2;
	int c;

	while (--argc > 0) {
		if(isnum(*++argv) == 1)
			push(atof(*argv));
		else {
			if (strlen(*argv) != 1) {
				printf("%s maybe a wrong parameter\n", *argv);
				return -1;
			}
			else {
				c = *argv[0];
				switch (c) {
				case '+':
					push(pop() + pop());
					break;
				case '-':
					p2 = pop();
					push(pop() - p2);
					break;
				case '*':
					push(pop() * pop());
					break;
				case '/':
					p2 = pop();
					push(pop() / p2);
					break;
				case '%':
					p2 = pop();
					push((int)pop() % (int)p2);
					break;
				default:
					printf("%c maybe a wrong operator\n", c);
					return -1;
					break;
				}
			}
		}
		printf("%s\n", *argv);
	}
	printf("Result is %g\n", pop());
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
