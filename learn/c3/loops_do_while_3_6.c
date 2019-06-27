#include <stdio.h>
#include <string.h>
#include <limits.h>

#define LENGTH 200
#define NUM -2354519

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
	int i;
	char s[LENGTH];
	char s2[LENGTH];

	itoa(INT_MIN+1, s);
	printf("%s\n", s);
	for (i = 0; s[i] != '\0'; i++)
		printf("%d ", s[i]);
	printf("\n");
	itoa(INT_MIN, s2);
	printf("%s\n", s2);
	for (i = 0; s2[i] != '\0'; i++)
		printf("%d ", s2[i]);

	return 0;
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
	} while ((n /= 10) > 0);		/* delete it */
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
