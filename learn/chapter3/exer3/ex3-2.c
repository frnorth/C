#include <stdio.h>

#define LENGTH 1000

void gettext2(char text[], int maxlength);
void escape(char s[], char t[]);

main()
{
	char s[LENGTH], t[LENGTH];

	gettext2(t, LENGTH);
	escape(s, t);

	printf("%s", s);

}

void gettext2(char text[], int maxlength)
{
	int i, c;

	for (i = 0; i < (maxlength - 1) && (c = getchar()) != EOF; i++)
		text[i] = c;
	text[i] = '\0';
}

void escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while(t[i] != '\0') {
		switch (t[i]) {
		case '\t':
			s[j++]= '\\';
			s[j++] = 't';
			i++;
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			i++;
			break;
		default:
			s[j++] = t[i++];
		}
	}
}
