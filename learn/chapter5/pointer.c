#include <stdio.h>

#define defprint(x) printf(#x ": %d\n", x)

main()
{
	int x = 10, y = 2, z[10];
	int *ip;

	defprint(ip);
	defprint(*ip);

	ip = &y;
	defprint(ip + 1);
	defprint(*(ip + 1));

	ip = &z[0];
	defprint(ip + 1);
	defprint(*(ip + 1));

	ip = z;
	defprint(ip + 1);
	defprint(*(ip + 1));

	return 0;
}
