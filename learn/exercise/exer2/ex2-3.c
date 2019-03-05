#include <stdio.h>
#include <math.h>

#define MAXLINE 30
unsigned int next = 1;

int htoi(char s[]);
int atoi(char s[]);
int lower(int c);
void getline3(char s[], int limit);
void srand(unsigned int seed);

main() {
	int num, i;
	char s[MAXLINE];

	getline3(s, MAXLINE);

	num = atoi(s);	
	printf("\n%s %d\n", s, num);

	num = htoi(s);	
	printf("\n%s %d\n", s, num);

	printf("%f\n", sqrt(2));

	//srand(10);
	//for (i = 0; i < 100; ++i)
	//	printf("%d\n", rand());
}

void getline3(char s[], int limit) {
	int c, i;

	for (i = 0; i < limit - 1; ++i) {
		c = getchar();
		if (c == '\n')
			i += limit;
		else if (c == EOF)
			i += limit;
		else {
			//c = lower(c);
			c = tolower(c);
			s[i] = c;
		}
	}

	if (i > limit - 1)
		i = i - limit + 1;
	s[i] = '\0';
}

/* atoi: convert s to integer */
int atoi(char s[]) {
	int i, n;

	n = 0;
	for (i = 0; /* s[i] >= '0' && s[i] <= '9' */ isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

int htoi(char s[]) {
	int i, tmp, n;

	i = 0;
	n = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		i = 2;
		while (s[i] != '\0' && ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))) {
			if (s[i] >= 'A' && s[i] <= 'F')
				tmp = s[i] - 'A' + 10;
			else if (s[i] >= 'a' && s[i] <= 'f')
				tmp = s[i] - 'a' + 10;
			else 
				tmp = s[i] - '0';
			n = 16 * n + tmp;
			++i;
		}
		return n;
	}
	else {
		printf("%s is not a hexadecimal number", s);
		return 0;
	}
}

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
	if (c >= 'A' && c <= 'Z')
		return  c + 'a' - 'A';
	else
		return c;
}

/* rand: return pseudo-random integer on 0..32767 */
int rand(void) {
	next = next * 1103515245 + 12345;
	printf("%d\t", next);
	return (unsigned int)(next/65536) % 32768;
}

/* scrand: set seed for rand */
void srand(unsigned int seed) {
	next = seed;
}
