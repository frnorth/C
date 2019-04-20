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

main()
{
	int state, c;
	int num[LENGTH];
	char s0[LENGTH];
	//char *s = "Hello World!";
	//char *s = s0;
	char *s = "haha1sdfsd";
	char *t = "haha1efsdf";

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
