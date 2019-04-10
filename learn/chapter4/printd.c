#include <stdio.h>

void printd(int d);

main()
{
	int num = 12345;
	printd(num);
	putchar('\n');
}

void printd(int d)
{
	if (d < 0) {
		putchar('-');
		d = -d;
	}
	if (d / 10)
	printd(d / 10);
	putchar(d % 10 + '0');
}
