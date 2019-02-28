#include <stdio.h>

main() {
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

	i=j=c=s=l=ui=uc=ul=us=f=d=ld=1;
	for (j = 0; j < 1023; ++j) {
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
		if (i > i*2) printf("int %d\n", i);
		if (c > c*2) printf("char %d\n", c);
		if (s > s*2) printf("short %d\n", s);
		if (l > l*2) printf("long %ld\n", l);
		if (ui > ui*2) printf("ui %d\n", ui);
		if (uc > uc*2) printf("uc %d\n", uc);
		if (us > us*2) printf("us %d\n", us);
		if (ul > ul*2) printf("ul %ld\n", ul);
		if (f > f*2) printf("%f\n", f);
		if (d > d*2) printf("%f\n", d);
		if (ld > ld*2) printf("%f\n", ld);
	}
	printf("\nint %d\n", i);
	printf("char %d\n", c);
	printf("short %d\n", s);
	printf("long %ld\n", l);
	printf("ui %d\n", ui);
	printf("uc %d\n", uc);
	printf("us %d\n", us);
	printf("ul %ld\n", ul);
	printf("%f\n", f);
	printf("%f\n", d);
	printf("%f\n", ld);

	return 0;
}
