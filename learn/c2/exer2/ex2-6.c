#include <stdio.h>

#define X 016677
#define Y (~0177700 - 1)
#define P 7
#define N 3

unsigned setbits (unsigned x, int p, int n, unsigned y);
unsigned invert (unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
void showbits (unsigned x);

main() {
	showbits(X);
	showbits(Y);
	showbits(rightrot(X, 7));
	showbits(rightrot(X, 6));
	showbits(rightrot(X, 5));
	//showbits(setbits(X,12,7,Y));
	//showbits(invert(X,12,7));
}

unsigned setbits (unsigned x, int p, int n, unsigned y) {
	if (p < n) {
		printf ("n > p, some bit will be ommited\n");
		n = p;
	}
	//showbits((~0 << p));
	//showbits(~(~0 << (p - n)));
	showbits(((~0 << p) | ~(~0 << (p - n))));
	showbits((y & ~(~0 << n)) << (p - n));
	return (x & ((~0 << p) | ~(~0 << (p - n)))) | ((y & ~(~0 << n)) << (p - n));
}

unsigned invert (unsigned x, int p, int n) {
	if (p < n) {
		printf ("n > p, some bit will be ommited\n");
		n = p;
	}

	unsigned kong = ((~0 << p) | ~(~0 << (p - n)));
	showbits(kong);
	showbits(~kong);
	
	return x ^ ~kong;
}

unsigned rightrot(unsigned x, int n) {
	unsigned i, num;

	num = 1;
	i = 1;
    while (i != (~i + 1)) {
        i = i << 1;
        num++;
    }

	return (x << (num - n)) | (x >> n);

}

void showbits (unsigned x) {
	unsigned i, num;

	num = 1;
	i = 1;
	while (i != (~i + 1)) {
		i = i << 1;
		num++;
	}
	for(; num > 0; num--)
		printf("%3d", num);

	printf("\n");
	while (i >= 1) {
		printf("%3d", ((x & i) != 0));
		i = i >> 1;
	}
	printf("\n\n");

}
