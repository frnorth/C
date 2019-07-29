#include <stdio.h>

#define LEN 100
int itoh(char *s, int n);

main()
{
	int c, len = 0;
	char s[LEN];

	while ((c = getchar()) != EOF) {
		if ( c == '\n' | c == '\t') {
			len += itoh(s, c);
			printf("%s", s);
		} else {
			putchar(c);
			len++;
		}
		if (len >= 20) {
			printf("\n");
			len = 0;
		}
		//switch(c) {
		//case '\t':
		//	itoh(s, c);
		//	printf("%s", s);
		//	break;
		//default:
		//	printf("%c", c);
		//	break;
		//}
	}
}


int itoh(char *s, int n)
{
	int len = 2, num;
	char *s_start = s;

	for (; n > 0; n /= 16) {
		num = n % 16;
		*s++ = (num > 9) ? ('A' + num - 10) : ('0' + num);
		len++;
		//sprintf("%c", (num > 9) ? ('A' + num - 10) : ('0' + num));
	}
	*s++ = 'x';
	*s++ = '0';
	*s = '\0';
	while (s_start < --s) {
		num = *s;
		*s = *s_start;
		*s_start = num;
		s_start++;
	}
	return len;
	//for(s_start = s; s_start)
}
