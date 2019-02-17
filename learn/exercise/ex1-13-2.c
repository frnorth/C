
#include <stdio.h>

#define IN 1
#define OUT 0
#define LENGTH 20
#define HIGHT 30

main() {
	int c, state, i, j, count;
	int length[LENGTH];
	int graph[LENGTH][HIGHT];

	for (i = 0;i < LENGTH; ++i)
		length[i] = 0;
	for (i = 0;i < LENGTH; ++i)
		for (j = 0; j < HIGHT; ++j)
			// 初始化成' '比较好, 如果是初始化成0, 而后面有没有改变这个值, 那么按照字符输出, 那就是'', 空!
			graph[i][j] = ' ';

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
		if (i < 10) {
			graph[i][1] = '0' + 0;
			graph[i][0] = '0' + i;
		}
		else if (i >= 10) {
			graph[i][1] = '0' + 1;
			graph[i][0] = '0' + (i - 10);
		}

		// 如果不加上这个检测, 也不会报错!?
		if (length[i] < (HIGHT -2))
			for (j = 2; j < length[i] + 2; ++j)
				graph[i][j] = '#';
		else 
			printf("too many words in length %d\n", i);
	}

	
	for (j = HIGHT-1; j >= 0; --j) {
		for (i = 0; i < LENGTH; ++i)
			printf("%c ",graph[i][j]);
		printf("\n");
	}
}
