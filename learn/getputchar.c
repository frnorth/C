#include <stdio.h>

/* copy input to output; 1st version */
//main() {
//	int c;
//
//	printf("%d\n",EOF);
//	c = getchar();
//	while (c != EOF) {
//		putchar(c);
//		c = getchar();
//	}
//}

/* copy input to output; 2nd version */
main() {
	int c;

	printf("EOF is %d\n",EOF);

	int b;
	while (b = (getchar() != EOF))
		//putchar(b); 这样是输出不出来的!!
		// 加\n与不加\n不一样。加了\n会输出两行, 不加\n...?
		printf("getchar() != EOF (try input fsfsdfwe) is %d\n",b);

	// EOF怎么输入?
	while ((c = getchar()) != EOF)
		putchar(c);
	
}
