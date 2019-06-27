#include <stdio.h>

#define LENGTH 200
#define MAX_LENGTH 1000

void gettext2(char text[], int maxlength);
void expands(char s1[], char s2[]);

main()
{
	int i;
	char s1[LENGTH];
	char s2[MAX_LENGTH];

	gettext2(s1, LENGTH);
	expands(s1, s2);
	printf("%s\n", s1);
	printf("%s\n", s2);

	return 0;
}

void gettext2(char text[], int maxlength)
{
	int i, c;

	for (i = 0; i < (maxlength - 1) && (c = getchar()) != EOF; i++)
		text[i] = c;
	text[i] = '\0';
}

void expands(char s1[], char s2[])
{
	int i, j, k;

	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '-') {
			if (i == 0 )
				s2[j++] = s1[i];
			else if (s1[i - 1] == '\t' || s1[i - 1] == ' ' )
				s2[j++] = s1[i];
			else if (s1[i + 1] <= s1[i - 1])
				s2[j++] = s1[i];
			else
				for (k = 1; (s1[i - 1] + k) < s1[i + 1]; k++, j++) {
					s2[j] = s1[i - 1] + k;
				}
		}
		else
			s2[j++] = s1[i];
	}
	s2[j] = '\0';
}
