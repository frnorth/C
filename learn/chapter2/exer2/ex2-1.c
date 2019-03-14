#include <stdio.h>

main() {
	int countf, countd, countld;
	int i, j;
	char c;
	short s;
	long l;
	unsigned int ui;
	unsigned char uc;
	unsigned short us;
	unsigned long ul;
	float f;
	double d;
	long double ld;

	countf = countd = countld = 0;
	i=j=c=s=l=ui=1;
	uc=1;
	ul=us=f=d=ld=1;
	for (j = 0; j < 1500; ++j) {
		i*=2;
		c*=2;
		s*=2;
		l*=2;
		ui*=2;
		uc*=2;
		us*=2;
		ul*=2;
		f*=2;
		d*=2;
		ld*=2;
		if (!((int)(i*2) >= i)) {
			printf("int %d\n", i);
			i = 0;
		}
		if (!(c*2 >= c)) {
			 printf("char %d\n", c);
			c = 0;
		}
		if (!(s*2 >= s)) {
			printf("short %d\n", s);
			s = 0;
		}
		if (!(l*2 >= l)) {
			printf("long %ld\n", l);
			l = 0;
		}
		if (!(ui*2 >= ui)) {
			printf("ui %d\n", ui);
			ui = 0;
		}
		if (!((unsigned char)(uc*2) >= uc)) {
			printf("uc %d\n", uc);
			uc = 0;
		}
		if (!((unsigned short)(us*2) >= us)) {
			printf("us %d\n", us);
			us = 0;
		}
		if (!(ul*2 >= ul)) {
			printf("ul %ld\n", ul);
			ul = 0;
		}
		if (!((float)(f*4) > (float)(f*2)) && countf == 0) {
			printf("%f\n", f);
			countf = 1;
		}
		if (!((double)(d*4) > (double)(d*2)) && countd == 0) {
			printf("%f\n", d);
			countd = 1;
		}
		if (!((long double)(ld*4) > (long double)(ld*2)) /*&& countld == 0*/) {
			printf("%f\n", ld);
			countld = 1;
		}
	}

	return 0;
}
