#include <stdio.h>

#define LENGTH 200

void gettext2(char text[], int maxlength);
void escape(char s[], char t[]);
void escape2(char s[], char t[]);

main()
{
	int i;
	char s[LENGTH], t[LENGTH];

	gettext2(t, LENGTH);
	//escape(s, t);
	escape2(s, t);

	printf("%s\n", s);
	for (i = 0; i< LENGTH; i++) {
		if (s[i] == '\0')
			printf("100");
		printf("%c", s[i]);
	}
	printf("\n\n");

	printf("%s\n", t);
	for (i = 0; i< LENGTH; i++) {
		if (s[i] == '\0')
			printf("100");
		printf("%c", t[i]);
	}
	printf("\n");

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
			break;
		}
	}
	s[i]=t[i];
}

void escape2(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while(t[i] != '\0') {
		switch (t[i]) {
		case '\\':
			switch (t[i + 1]) {
			case 't':
				s[j++]= '\t';
				i+=2;
				break;
			case 'n':
				s[j++] = '\n';
				i+=2;
				break;
			default:
				s[j++] = t[i++];
				break;
			}
			break;
		default:
			s[j++] = t[i++];
			break;
		}
	}
	s[i]=t[i];
}
