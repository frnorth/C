#include <stdio.h>
#include <limits.h>
#include <string.h>

#define LENGTH 200

void itoa(int n, char s[]);
void itoa2(int n, char s[], int w);
void itob(int n, char s[], int b);
void reverse(char s[]);
void showbits (int x);

main()
{
	char s[LENGTH];

	/*
	showbits(INT_MIN+8);
	showbits(-1);
	showbits(-3);
	showbits(-16);
	showbits(INT_MAX);
	if(INT_MIN < 0)
		printf("%d\n", INT_MIN);
	printf("%d\n", INT_MAX);
	*/

	itoa(1234, s);
	printf("%s\n", s);
	itoa2(1234, s, 7);
	printf("%s\n", s);
	itoa2(-123456789, s, 5);
	printf("%s\n", s);
	itoa2(-123456789, s, 10);
	printf("%s\n", s);
	itoa2(-123456789, s, 20);
	printf("%s\n", s);

	itoa(INT_MAX, s);
	printf("%s\n", s);
	itob(INT_MAX, s, 8);
	printf("%s\n\n", s);
	itoa(INT_MIN, s);
	printf("%s\n", s);
	itob(INT_MIN, s, 10);
	printf("%s\n", s);
	itob(INT_MIN, s, 8);
	printf("%s\n\n", s);
	itob(INT_MIN, s, 2);
	printf("%s\n\n", s);
	itob(INT_MIN, s, 16);
	printf("%s\n\n", s);
	itob(-16, s, 8);
	printf("%s\n", s);
	itob(-16, s, 16);
	printf("%s\n", s);

}

void showbits (int x) {
	unsigned i, num;

	num = 0;
	i = 1;
	while (i != (~i + 1)) {
		i = i << 1;
		printf("%3d", num++);
	}
	printf("%3d", num++);
	printf("\n");
	while (i >= 1) {
		printf("%3d", ((x & i) != 0));
		i = i >> 1;
	}
	printf("\n");
	printf("\n");
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	do {	/* generate digis in reverse order */
		s[i++] = sign * (n % 10) + '0';	/* get next digit */
		//printf("%d, %d, %d, %d, %c\n", n % 10, n / 10, n, -1 * n, s[i-1]); /* an interesting statement */
	} while ((n /= 10) != 0);		/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itoa2(int n, char s[], int w)
{
	int i, sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	do {
		s[i++] = sign * (n % 10) + '0';	/* get next digit */
	} while ((n /= 10) != 0);		/* delete it */
	if (sign < 0)
		s[i++] = '-';
	for (;i < w; i++)
		s[i] = ' ';
	s[i] = '\0';
	reverse(s);
}

void itob(int n, char s[], int b)
{
	int i, sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	do {
		s[i++] = sign * (n % b) + '0';
	} while ((n /= b) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
