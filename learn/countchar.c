#include <stdio.h>

/* count characters in input; 1st version */
main() {
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	// 1d还是0d?,, 是ld, 小写的'L'!
	printf("%ld\n",nc);
}

/* count characters in input; 1st version */
//main() {
//	double nc;
//
//	for (nc =0 ; getchar() != EOF; ++nc)\
//		;
//	// .0f还是.1f?
//	printf("%.0f\n",nc);
//}
