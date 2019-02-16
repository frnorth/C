#include <stdio.h>

/* count lines in input */
main() {
	int c,nl;

	nl = 0;
	// 当输入了一串sfsbgsfsdfs, 按ctrl+d, 这个时候只是停止本次输入, 而不是getchar()一个ctrl+d, 所以getputchar.c运行后, 输入sfsdfsdf, ctrl+d, 不换行, 直接输出了输入的!
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	//putchar(nl); 这个用不了, 因为nl不是getchar进来的?
	printf("%d\n", nl);
}
