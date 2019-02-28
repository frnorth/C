#include <stdio.h>

#define MAXLENGTH 10000

int getword(char program[], int maxlength);
void decomment(char program[], char pureprogram[]);
void checkpair(char program[], char c1, char c2);
void checknest(char program[], char c1, char c2, char c3, char c4);
void checkquote(char program[], char c);

main() {
	int len;
	char program[MAXLENGTH], pureprogram[MAXLENGTH];

	len = getword(program, MAXLENGTH);
	decomment(program, pureprogram);
	printf("%s", pureprogram);


	checkquote(program, '"');
	checkquote(program, '\'');

	checkpair(program, '(', ')');
	checkpair(program, '[', ']');
	checkpair(program, '{', '}');

	checknest(program, '(', ')', '[', ']');

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
	int i, count, line;

	i = 0;
	count = 0;
	line = 1;
	while (program[i] != '\0') {
			
		if (program[i] == c1)
			++count;
		if (program[i] == c2)
			--count;
		if (program[i] == '\n')
			++line;
		if (count < 0) {
			printf("Lack of %c in line %d\n", c1, line);
			count = 0;
		}
		++i;
	}
	if (count > 0)
		printf("Lack of %d %c\n", count, c2);
}
void checknest(char program[], char c1, char c2, char c3, char c4) {
	int i, count1, count2, nest, condi, line;

	i = 0;
	count1 = 0;
	count2 = 0;
	nest = 0;
	line = 1;
	condi = 0;
	while (program[i] != '\0') {
		if (program[i] == '\n')
			++line;

		if (program[i] == c1)
			++count1;
		if (program[i] == c2)
			--count1;
		if (program[i] == c3)
			++count2;
		if (program[i] == c4)
			--count2;

		if (count1 > 0 && count2 == 0 )
			condi == 1;
		if (condi == 1 && count2 > 0)
			nest == 1;
		if (nest == 1 && count1 == 0 && count2 > 0)
			printf("nest like %c %c %c in line %d", c1, c3, c2, line);
		if (nest == 1 && count1 > 0 && count2 == 0)
			nest == 0;
		if (condi == 1 && count1 == 0 && count2 == 0)
			condi == 0;

		if (count1 == 0 && count2 > 0 )
			condi == 2;
		if (condi == 2 && count1 > 0)
			nest == 1;
		if (nest == 1 && count1 > 0 && count2 == 0)
			printf("nest like %c %c %c in line %d", c3, c1, c4, line);
		if (nest == 1 && count1 == 0 && count2 > 0)
			nest == 0;
		if (condi == 2 && count1 == 0 && count2 == 0)
			condi == 0;
		

		++i;
	}
}
void checkquote(char program[], char c) {
	int i, count, line;

	i = 0;
	count = 0;
	line = 1;
	while (program[i] != '\0') {
			
		if (program[i] == c) {
			if (count == 1)
				count = 0;
			if (count == 0)
				count = 1;;
		}
		++i;
	}
	if (count == 1)
		printf("Lack of a %c\n", c);
}
