#include <stdio.h>

#define MAXLINE 100 /* maximum input line length */

/* find all lines matching pattern */
main()
{
	/* 在main里声明也行? */
	/* 声明atof(char s[])也行..?! */
	double sum, atof2(char []);
	char line[MAXLINE];
	int sum_int, etline2(char line[], int max), atoi(char []);

	sum = 0;
	sum_int = 0;
	while (getline2(line, MAXLINE) > 0) {
		printf("\t%g\n", atof2(line));
		printf("\t%g\n", sum += atof2(line));
		/* 貌似 %d, %g一定要写对, 不然错误无法预知,,? */
		printf("\t%d\n", sum_int += atoi(line));
	}
	return 0;
}
