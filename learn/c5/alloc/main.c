#include <stdio.h>

#define defprinti(x) printf(#x ": %d\n", x)
#define defprints(x) printf(#x ": %s\n", x)

char *alloc(int);
void afree(char *);

main()
{
	char *s1 = alloc(200);
	char *s2 = alloc(200);
	char *ss = 0;
	/* 0 is the sole exception */
	//char *tt = 12;

	/* this would reaise segment fault, while defprinti(ss) would not */
	defprinti(ss);
	defprints(ss);
	if (ss == NULL)
		defprinti(ss);
	//defprinti(tt);
	//defprints(tt);

	defprinti(s1);
	defprints(s1);
	defprinti(s2);
	s1[0] = 'h';
	s1[1] = 'e';
	s1[2] = 'l';
	defprints(s1);
	defprinti(s1);

	afree(s1);
}
