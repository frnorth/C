#include <stdio.h>
#include <string.h>

#define LENGTH 200

void gettext2(char text[], int maxlength);

main()
{
	int len;
	char s[LENGTH];

	gettext2(s, LENGTH);
	len = trim(s);
	printf("%s\n", s);
	
	return 0;
}

void gettext2(char text[], int maxlength)
{
	int i, c;

	for (i = 0; i < (maxlength - 1) && (c = getchar()) != EOF; i++)
		text[i] = c;
	text[i] = '\0';
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--) {
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
		if (s[n] == ' ')
			continue;
		printf("%d\n", s[n] - '0');
	}
	s[n+1] = '\0';
	return n;
}
