#include <stdio.h>

#define X 02

int bitcount(unsigned x);
int bitcount2(unsigned x);
void showbits(unsigned x);

main() {
	int i;

	showbits(X);
	printf("%d %d %d\n", X, bitcount(X), bitcount2(X));

	for (i = 0; i < X; i++)
		printf("%6d%c", i, (i % 10 == 9 || i == X - 1) ? '\n' : ' ');

	printf("You have %d item%s.\n", X, (X == 1) ? "" : "s");
}

/* bitcount: count 1 bitsin x */
int bitcount(unsigned x) {
	int b;

	for (b = 0;x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

int bitcount2(unsigned x) {
	int num;

	num = 1;
	while(x &= (x - 1))
		num++;
	return num;
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
