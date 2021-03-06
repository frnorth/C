#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LENGTH 200
#define NUM_LENGTH 15

void gettext2(char text[], int maxlength);
void shellsort(int v[], int n);
void reverse(char s[]);

main()
{
	int i;
	char t[LENGTH];

	gettext2(t, LENGTH);
	reverse(t);
	printf("%s\n", t);

	if(1 > 2, 2 > 1)
		printf("%d\n", i);

	/*
	int num[NUM_LENGTH];

	for (i = 0; i < NUM_LENGTH; i++) {
		printf("the %d th num: ", i);
		gettext2(t, LENGTH);
		num[i] = atoi(t);
	}
	shellsort(num, NUM_LENGTH);
	for (i = 0; i < NUM_LENGTH; i++)
		printf("%d\n", num[i]);
	*/

	return 0;
}

void gettext2(char text[], int maxlength)
{
	int i, c;

	for (i = 0; i < (maxlength - 1) && (c = getchar()) != EOF; i++)
		text[i] = c;
	text[i] = '\0';
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') /* skip sign */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + s[i] - '0';
	return n * sign;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /=2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >=0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
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
