#include <stdio.h>

#define LENGTH 1000
void reverse(char s[]);

main()
{
	char s[] = "1234567890abvdefg";

	reverse(s);
	printf("%s\n", s);
}

void reverse(char s[])
{
	int tmp;
	static int len = 0;
	static int i = 0;

	if (s[len] != '\0') {
		len++;
		reverse(s);
	}
	printf("%d %d\n", i, len);
	if (i < len - 1) {
		tmp = s[--len];
		s[len] = s[i];
		s[i++] = tmp;
	}
}
