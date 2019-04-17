#include <stdio.h>

#define defprint(x) printf(#x ": %d\n", x)
#define defprintc(x) printf(#x ": %c\n", x)
#define defprints(x) printf(#x ": %s\n", x)

void swap(int *pa, int *pb);

main()
{
	int i, x = 10, y = 2, z[10], k[10];
	int *ip, *iq, *ir;
	char *ipc, *iqc, *irc;

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
	defprint(ip);
	defprint(ip + 1);
	defprint(*(ip + 1));
	defprint(ipc);
	defprint(ipc + 1);

	iq = ip;
	defprint(iq);
	defprint(*iq);
	defprint(*(iq-1000));


	defprint(x);
	defprint(y);
	swap(&x, &y);
	defprint(x);
	defprint(y);

	/*C programing languange page 99 -- By definition, the value of a variable or expression of type array is the address of element zero of the array. ..?*/
	defprint(z);
	defprint(&z[0]);

	defprint(strlen2("Hello World!"));

	/* 数组是可以越界的? */
	z[-1] = -111;
	z[100] = 22;
	defprint(z[-1]);
	defprint(z[100]);
	for (i = -100; i < 100; i++) {
		printf("%d ", i);
		defprint(k[i]);
	}

	if (ip > ir)
		printf("yead, ip: %d, ir: %d\n", ip, ir);
	if (ip <= ir)
		printf("yead, ip: %d, ir: %d\n", ip, ir);

	iqc = "abcdefg";
	defprint(iqc);
	defprintc(*iqc);
	defprint(iqc + 1);
	defprintc(*(iqc + 1));
	/* can not modify the contents ...! */
	//*(iqc + 1) = 'h';
	defprintc(*(iqc + 1));
	defprints(iqc);

	return 0;
}

void swap(int *pa, int *pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int strlen2(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}
