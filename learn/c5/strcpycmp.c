#include <stdio.h>

#define defprint(x) printf(#x ": %d\n", x)
#define defprintc(x) printf(#x ": %c\n", x)
#define defprints(x) printf(#x ": %s\n", x)

void strcpy2(char *, char *);
int strcmp_hehe(char *, char *);
int strcmp(char *, char *);

main()
{
	int state;
	char *s = "Hello World!";
	char *t = "Hahahah";

	//strcpy2(s, t);
	defprints(s);
	defprint(s);
	defprints(t);
	defprint(t);

	state = strcmp_hehe(s, t);
	defprint(strcmp(s, t));

	return 0;
}

void strcpy2(char *s, char *t)
{
	while (*t++ = *s++)
		;
}

int strcmp_hehe(char *s, char *t)
{
	char *ps = s, *pt = t;

	printf("%s %s\n", ps, pt);
	while (*s != '\0' && *t != '\0') {
		if (*s > *t) {
			printf("%s > %s\n", ps, pt);
			return 1;
		}
		if (*s < *t) {
			printf("%s < %s\n", ps, pt);
			return 0;
		}
		t++;
		s++;
	}
	if (*s != '\0') {
		printf("%s > %s\n", ps, pt);
		return 1;
	}
	if (*t != '\0') {
		printf("%s < %s\n", ps, pt);
		return 0;
	}
	
	printf("%s = %s\n", ps, pt);
	return 2;
}

int strcmp(char *s, char *t)
{
	for(; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
