#include <stdio.h>

#define MAXLEN 500

int getline2(char *s, int lim);

main()
{
	double sum, v;
	char line[MAXLEN];

	//sum = 0;
	//while (scanf("%lf", &v) == 1)
	//	printf("\t%.2f\n", sum += v);

	int day, month, year, num;
	char monthname[20];

	//scanf("%d %s %d", &day, monthname, &year);
	//printf("==>\n%d\n%s\n%d\n", day, monthname, year);

	/* 像下面这样, 是不行的, %s后面的"/"不会被单独识别出来 */
	//scanf("%d/%s/%d", &day, monthname, &year);
	//printf("-------->\n%d\n%s\n%d\n", day, monthname, year);
	//num = scanf("%d/%d/%d", &day, &month, &year);
	//printf("-------->\n%d\n%d\n%d\n%d\n", day, month, year, num);

	while (getline2(line, MAXLEN) > 0) {
		//if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
		/* %d%s%d 之间可以不用空格!? */
		if (sscanf(line, "%d%s%d", &day, monthname, &year) == 3)
			printf("==>\n%d\n%s\n%d\n", day, monthname, year);
		else if (sscanf(line, "%d:/%d/%d", &day, &month, &year) == 3)
			printf("-------->\n%d\n%d\n%d\n", day, month, year);
		else
			printf("invalid: %s\n", line);
	}

	return 0;
}

/* getline: get line into s, return length */
int getline2(char *s, int lim)
{
    int c;
    char *s0 = s;

    while (--lim  && (c = getchar()) != EOF) {
        *s++ = c;
        if (c == '\n')
            break;
    }
    *s = '\0';
    return s - s0;
}

