#include <stdio.h>
#include <float.h>
#include <limits.h>

#define VTAB '\xb'
#define BELL '\x7'

main() {
	enum boolean { NO, YES };

	printf("%d\n", INT_MAX);
	printf("%ld\n", LONG_MAX); // 注意这里要 %ld
	printf("%f\n", FLT_MAX);
	printf("%lf\n", DBL_MAX);
	printf("%d, %d\n", NO, YES);

	printf("%d%c%d\n", '\0', VTAB, '\0');
	printf("%c\n", BELL);
};
