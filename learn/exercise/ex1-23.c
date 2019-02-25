#include <stdio.h>

#define MAXLENGTH 10000

int getword(char program[], int maxlength);
void decomment(char program[], char pureprogram[]);

main() {
	int len;
	char program[MAXLENGTH], pureprogram[MAXLENGTH];

	len = getword(program, MAXLENGTH);
	decomment(program, pureprogram);

	printf("%s", pureprogram);
	if (len >= MAXLENGTH - 1)
		printf("Too many words!\n");

	return 0;
}

int getword(char program[], int maxlength) {
	char c;
	int i;

	for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF; ++i)
		program[i] = c;
	program[i] = '\0';

	return i;
}

void decomment(char program[], char pureprogram[]) {
	int i, j, state;

	i = 0;
	j = 0;
	state = 0;
	if (program[0] == '*') {
		printf("It seems like being a wrang program!\n");
		/* ? exit再哪个库里?  */
		//exit(-1);
	}
	while (program[i] != '\0') {
		/* program[i] != '\0' 这个判断能够保证program[i + 1] 不越界*/
		if (program[i] == '/' && program[i + 1] == '*')
			state = 1;
		else if (program[i] == '/' && program[i - 1] == '*') {
			state = 0;
			++i;
		}

		if (state == 1)
			++i;
		if (state == 0) {
			pureprogram[j] = program[i];
			++i;
			++j;
		}
	}
}
