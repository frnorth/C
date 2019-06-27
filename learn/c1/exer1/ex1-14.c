#include <stdio.h>

#define LENGTH 94

main() {
	int c, i, j;
	int characters[LENGTH];

	for (i = 0; i< LENGTH; ++i)
		characters[i] = 0;

	while ((c = getchar()) != EOF) {
		for (i = 0; i < LENGTH; ++i)
			if (c == '!' + i)
				++characters[i];
	}

	for (i = 0; i < LENGTH; ++i) {
		printf("%c %d:", '!' + i, characters[i]);
		for (j = 0; j < characters[i]; ++j)
			printf("#");
		printf("\n");
	}

	// 由此可见 '!' --> '~' 是一些基本常用的符号, 位置连续, 后面还有一些牛逼的符号!
	//for (i = 0; i < 400; ++i)
	//	printf("%3d  %c\n", i, '0'+i);



}
