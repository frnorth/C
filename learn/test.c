#include <stdio.h>
#include <float.h>
#include <limits.h>

struct haha{};

main() {
	printf("%d\n",INT_MAX);
	printf("%ld\n",LONG_MAX); // 注意这里要 %ld
	printf("%f\n",FLT_MAX);
	printf("%lf\n",DBL_MAX);
};
