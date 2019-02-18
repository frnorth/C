#include <stdio.h>

main() {
	int c, cprior;


	while((c = getchar()) != EOF) {
		// 记得有一个情况putchar不能用了, 啥情况来着?
		if (cprior != ' ')
			putchar(c);
		if (cprior == ' ')
			if (c != ' ')
			putchar(c);
		cprior = c;
	}
}
