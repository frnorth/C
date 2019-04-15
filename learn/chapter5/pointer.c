#include <stdio.h>

#define defprint(x) printf(#x ": %d\n", x)

void swap(int *pa, int *pb);

main()
{
	int x = 10, y = 2, z[10];
	int *ip, *iq;

	/* 打开这个注释, 就会报段错误? */
	//defprint(ip);
	//defprint(*ip);

	ip = &y;
	defprint(ip + 1);
	defprint(*(ip + 1));

	ip = &z[0];
	defprint(ip + 1);
	defprint(*(ip + 1));

	ip = z;
	defprint(ip + 1);
	defprint(*(ip + 1));

	iq = ip;
	defprint(iq);
	defprint(*iq);


	defprint(x);
	defprint(y);
	swap(&x, &y);
	defprint(x);
	defprint(y);

	return 0;
}

void swap(int *pa, int *pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
