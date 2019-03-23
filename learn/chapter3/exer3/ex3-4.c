#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);
void showbits (int x);

main()
{
	showbits(INT_MIN+8);
	showbits(-1);
	showbits(-3);
	showbits(-16);
	showbits(INT_MAX);

	if(INT_MIN < 0)
		printf("%d\n", INT_MIN);
	printf("%d\n", INT_MAX);

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

	if ((sign = n) < 0) /* record sign */
		n = -n;			/* make n positive */
	i = 0;
	do {	/* generate digis in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
		printf("%d, %d, %d, %d, %c\n", n % 10, n / 10, n, -1 * n, s[i-1]); /* an interesting statement */
	} while ((n /= 10) != 0);		/* delete it */
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
