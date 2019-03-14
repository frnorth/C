
#include <stdio.h>

#define IN 1
#define OUT 0
#define LENGTH 20

main() {
	int c, state, i, j, count;
	int length[LENGTH];

	for (i = 0;i < LENGTH; ++i)
		length[i] = 0;

	state = OUT;
	count = 0; // 这里还是需要初始化, 不然会报错Segmentation fault
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				++length[count];
				count = 0;
			}
			state = OUT;
		}
		else {
			++count;
			state = IN;
		}
	}

	for (i = 0; i < LENGTH; ++i) {
		printf("number of word of length %2d: ", i);
		for (j = 0; j < length[i]; ++j)
			printf("#");
		printf("\n");
	}
}
