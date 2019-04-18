#include <stdio.h>

#define LENGTH 1000

#define defprint(x) printf(#x ": %d\n", x)
#define defprintc(x) printf(#x ": %c\n", x)
#define defprints(x) printf(#x ": %s\n", x)

void strcat2(char *s, char *t);

main()
{
	int state, c;
	char s0[LENGTH];
	//char *s = "Hello World!";
	char *s = s0;
	char *t = "Hahahah";

	while ((c = getchar()) != EOF)
		*s++ = c;

	defprint(*s);
	defprints(s);
	defprint(s);
	defprints(s0);
	defprint(s0);
	defprints(t);
	defprint(t);

	strcat2(s0, t);
	defprints(s);
	defprints(s0);

	return 0;
}

void strcat2(char *s, char *t)
{
	for (; *s != '\0'; s++)
		;
	while (*s++ = *t++)
		;
}
