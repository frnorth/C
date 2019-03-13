#include <stdio.h>

#define BE_SET 0177
#define SET_ON ~0177700
#define START 6
#define STOP 3

unsigned getbits (unsigned x, int p, int n);
void showbits (unsigned x);

main() {
	
	printf("%d\n", BE_SET);
	printf("%d\n", SET_ON);
	printf("%d\n", getbits(BE_SET, START, STOP));

	showbits(BE_SET);
	showbits(SET_ON);
	showbits(getbits(BE_SET, START, STOP));
	showbits(BE_SET & SET_ON);
	showbits(BE_SET ^ SET_ON);
	//showbits(~0 << -2);

}

/* getbits: get n bits from position p */
unsigned getbits (unsigned x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
}

void showbits (unsigned x) {
	unsigned i, num;

	num = 0;
	i = 1;
	while (i != (~i + 1)) {
		i = i << 1;
		printf("%3d", num++);
	}
	printf("%3d", num++);
	//printf("%3d", num++); // test out of the bonder

	printf("\n");
	while (i >= 1) {
		printf("%3d", ((x & i) != 0));
		i = i >> 1;
	}
	//printf("%3d", ((x & i) != 0)); // test out of the bonder
	printf("\n");

	//for (i = num = 1; num < 100; num ++) {
	//	printf("%3d", ((x & i) != 0));
	//	i = i >> 1;
	//}
	printf("\n");
}
