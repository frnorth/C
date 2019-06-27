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
	int i, count1, count2, type, nesttype, line;

	i = 0;
	count1 = 0;
	count2 = 0;
	type = 0;
	nesttype = 0;
	line = 1;
	while (program[i] != '\0') {
		if (program[i] == '\n')
			++line;

		/* 判断括号的状态 judge the state of () and [] */
		if (program[i] == c1)
			++count1;
		if (program[i] == c2)
			--count1;
		if (program[i] == c3)
			++count2;
		if (program[i] == c4)
			--count2;

		/* judge the state of type ((( or [[[ or ' ' */
		if (type == 0) {
			if (count1 > 0)
				type = 1;
			else if (count2 > 0)
				type = 2;
		}
		else if (type == 1) {
			if (count1 == 0)
				type = 0;
			/* 基于type值的type值转换判断, 与基于type值的nesttype值判断, 是否可以供用一个 else if(type==1) ? */
			///* 如果是else if, ( [ ) 这种情况, if(count==0)type==0之后还会继续执行if(count2>0)nest==1 */
			///* 如果是else if, 那么tpye值转换的判断成功会影响nesttype值的判断 */
			if (count2 > 0)
				nesttype = 1;
			else if (count2 == 0)
				nesttype = 0;
		}
		else if (type == 2) {
			if (count2 == 0)
				type = 0;
			/* [ ( */
			if (count1 > 0)
				nesttype = 2;
			else if (count1 == 0)
				nesttype = 0;
		}

		if (nesttype == 1) {
			if (program[i] == c2)
				printf("nest %c %c %c at line %d\n", c1, c3, c2, line);
			else if (program[i] == c1)
				type == 2;
		}
		if (nesttype == 2) {
			if (program[i] == c4)
				printf("nest %c %c %c at line %d\n", c3, c1, c4, line);
			else if (program[i] == c3)
				type == 1;
		}

		printf("%d %d %d %d\n", count1, count2, type, nesttype);

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
