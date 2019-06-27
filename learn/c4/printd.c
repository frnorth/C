#include <stdio.h>

#define LENGTH 100

void printd(int d);
void printd2(int d, char s[]);

main()
{
	int num = 12345;
	char s[LENGTH];

	num = -1 * num;
	printd(num);
	printf("\n");
	printd2(num, s);
	printf("%s\n", s);
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

void printd2(int d, char s[])
{
	static i = 0;

	//i = 0;
	if (d < 0) {
		s[i] = '-';
		//printf("%d\n", i);
		d = -d;
		i++;
	}
	printf("  %d\n", i);
	if (d / 10)
	printd2(d / 10, s);
	printf("%d\n", i);
	//i = 0;
	s[i++] = d % 10 + '0';
	s[i] = '\0';
}
