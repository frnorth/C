#include <stdio.h>

/* count lines in input */
main() {
	int c,n1;

	n1 = 0;
	// 当输入了一串sfsbgsfsdfs, 按ctrl+d, 这个时候只是停止本次输入, 而不是getchar()一个ctrl+d, 所以getputchar.c运行后, 输入sfsdfsdf, ctrl+d, 不换行, 直接输出了输入的!
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++n1;
	printf("%d\n", n1);
}
