#include <stdio.h>

#define MAXLENGTH 10000

int getword(char program[], int maxlength);
void decomment(char program[], char pureprogram[]);
void checkpair(char program[], char c1, char c2);
void checkpairquote(char program[], char c1, char c2);

main() {
	int len;
	char program[MAXLENGTH], pureprogram[MAXLENGTH];

	len = getword(program, MAXLENGTH);
	decomment(program, pureprogram);
	printf("%s", pureprogram);

	checkpair(program, '(', ')');
	checkpair(program, '[', ']');
	checkpair(program, '{', '}');

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

void checkpair(char program[], char c1, char c2) {
	int count, i, line;

	i = 0;
	count = 0;
	while (program[i] != '\0') {
		if (program[i] == c1)
			++count;
		if (program[i] == c2)
			--count;
		++i;
	}
	if (count > 0)
		printf("lack of %d %c\n", count, c2);
	if (count < 0)
		printf("lack of %d %c\n", -1 * count, c1);
}
void checkpairquote(char program[], char c1, char c2) {
	int count, i, line;

	i = 0;
	line = 1;
	while (program[i] != '\0') {
		if (program[i] = '\n')
			++line;
		if (program[i] == c2)
			if (count > 1)
				printf("lake %d %c ", count -1, c1);
	}
}
