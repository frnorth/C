#include <stdio.h>
#include <ctype.h>

#define LENGTH 200

void gettext2(char text[], int maxlength);

main()
{
	int i;
	char t[LENGTH];

	gettext2(t, LENGTH);
	printf("%d\n", atoi(t));

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
