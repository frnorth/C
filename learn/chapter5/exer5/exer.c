#include <stdio.h>

#define LENGTH 1000

#define defprint(x) printf(#x ": %d\n", x)
#define defprintc(x) printf(#x ": %c\n", x)
#define defprints(x) printf(#x ": %s\n", x)

void strcat2(char *s, char *t);
int getline2(char *s, int lim);
int strend(char *s, char *t);
int strend2(char *s, char *t);
void strncpy2(char *s, char *t, int n);
void strncat2(char *s, char *t, int n);
int atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);

main()
{
	int state, c;
	int num[LENGTH];
	char s0[LENGTH];
	//char *s = "Hello World!";
	//char *s = s0;
	char *s = "dgdfhaha1sdf";
	char *t = "1s";
	//char *s = "";
	//char *t = "";
	char *num2 = "123456";

	//getline2(s0, LENGTH);

	//while ((c = getchar()) != EOF)
	//	*s++ = c;

	printf("\n");
	defprint(*s);
	defprints(s);
	defprint(s);
	defprints(s0);
	defprint(s0);
	defprints(t);
	defprint(t);

	//strcat2(s0, t);
	defprints(s);
	defprints(s0);

	/* distance of address in 4 would result in number 1, for int arrays */
	defprint(&num[0]);
	defprint(&num[1]);
	defprint(&num[1] - &num[0]);

	/* exer 5-4 */
	defprint(strend(s, t));

	/* exer 5-5 1 */
	strncpy2(s0, t, 2);
	defprints(s0);

	/* exer 5-5 2 */
	strncat2(s0, t, 10);
	defprints(s0);

	/* exer 5-5 3 */
	defprint(strncmp2(s, t, 5));

	/* exer 5-5 4 */
	defprint(atoi("  -25452211  "));

	/* exer 5-5 5 */
	itoa(12345, s0);
	defprints(s0);

	/* exer 5-5 6 */
	defprint(strindex(s, t));

	return 0;
}

void strcat2(char *s, char *t)
{
	for (; *s != '\0'; s++)
		;
	while (*s++ = *t++)
		;
}

/* getline: get line into s, return length */
int getline2(char *s, int lim)
{
	int c;
	char *s0 = s;

	while (--lim  && (c = getchar()) != EOF) {
		*s++ = c;
		if (c == '\n')
			break;
	}
	*s = '\0';
	return s - s0;
}

/* exer 5-4 */
int strend2(char *s, char *t)
{
	char *s0 = s;
	char *t0 = t;

	for (; *s != '\0'; s++)
		;
	for (; *t != '\0'; t++)
		;
	while (*--s == *--t)
		;
	if (*++t == *t0)
		return 1;
	else
		return 0;
}
int strend(char *s, char *t)
{
	char *t0 = t;

	while (*s != '\0') {
		for (; *s != *t; s++)
			;
		while (*++s == *++t)
			if (*s == '\0')
				return 1;
		t = t0;
	}
	return 0;
}

void strncpy2(char *s, char *t, int n)
{
	char *t0 = t;

	while (*s++ = *t++)
		if ((t - t0) >= n) {
			*s = '\0';
			break;
		}
}

void strncat2(char *s, char *t, int n)
{
	char *t0 = t;

	for (; *s != '\0'; s++)
		;
	while (*s++ = *t++)
		if ((t - t0) >= n) {
			*s = '\0';
			break;
		}
}

int strncmp2(char *s, char *t, int n)
{
	char *t0 = t;

	for (; (t - t0 < n - 1) && (*s == *t); s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int atoi(char *s)
{
	int sign, num;

	for (; isspace(*s); s++)
		;
	sign = *s == '-' ? -1 : 1;
	if (sign == '+' || *s == '-')
		s++;
	for (num = 0; isdigit(*s); s++)
		num = num * 10 + *s - '0';
	return num * sign;
}

void itoa(int n, char *s)
{
	char *s0 = s;

	int sign = n > 0 ? 1 : -1;

	n = sign * n;
	do {
		defprintc(*s);
		*s++ = n % 10 + '0';
	} while (n /= 10);
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	defprints(s0);
	reverse(s0);
}

void reverse(char *s)
{
	int tmp;
	char *t = s;

	for (; *t != '\0'; t++)
		;
	while (t > s) {
		tmp = *--t;
		defprintc(*s);
		defprintc(*t);
		*t = *s;
		*s++ = tmp;
	}
}

int strindex(char *s, char *t)
{
	char *tmpt, *tmps, *s0 = s;
	for (; *s != '\0'; s++) {
		//for (tmpt = t, tmps = s; *tmpt != '\0' && *tmpt == *tmps; tmpt++, tmps++)
		//	;
		//if (tmpt != t && *tmpt == '\0')
		//	return s - s0 + 1;
		for (tmpt = t, tmps = s; *tmpt++ == *tmps++;)
			if (*tmpt == '\0')
				return s - s0 + 1;
	}
	return -1;
}
