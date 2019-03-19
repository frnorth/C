#include <stdio.h>

#define LENGTH 200
#define MAX_LENGTH 1000

void gettext2(char text[], int maxlength);

main()
{
	int i;
	char s1[LENGTH];
	char s2[MAX_LENGTH];

	gettext2(s1, LENGTH);

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
	int i, j;

	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '-') {
			if (i == 0 )
				;
			else if ( )
		}
	}
}
