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
	//putchar(b);
	//b=getchar();
	//putchar(b);
	printf("getchar() != EOF  is %d\n",(getchar() != EOF));
	while (b = (getchar() != EOF))
		//putchar(b); 这样是输出不出来的!!
		// 加\n与不加\n不一样。加了\n会输出两行, 不加\n...?
		// 回车是结束本次输入, 但同时也是个字符? ...?
		printf("getchar() != EOF (try input fsfsdfwe) is %d\n",b);
		//putchar(b); 这个时候不能用putchar()输出, 为什么? putchar()只能输出刚从getchar()输入进来的?

	// EOF怎么输入? ctrl+d
	// 回车结束本次输入, 而同时也被作为字符输出了出来, 所以puchar()结束后才会有换行! 而单敲回车是换两行!
	while ((c = getchar()) != EOF)
		putchar(c);
	
}
