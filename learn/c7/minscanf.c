#include <stdio.h>
#include <stdarg.h>

#define MAXLEN 500
#define defprint(type, x) printf(#x ": %" #type"\n", x)

main()
{
	void minscanf(char *fmt, ...);

	double sum, v;
	char line[MAXLEN];

	int day, month, year, num;
	char monthname[20];

	//minscanf("%d%s%d", &day, monthname, &year);
	//printf("==>\n%d\n%s\n%d\n", day, monthname, year);
	minscanf("%d:/%d/%d", &day, &month, &year);
	printf("-------->\n%d\n%d\n%d\n", day, month, year);

	return 0;
}

void minscanf(char *fmt, ...)
{
	int c, c2, *ival;
	double *dval;
	char *p, *p2, *sval;

	va_list pa;
	va_start(pa, fmt);

	for (p = fmt; *p; p++) {
		c = *p;
		defprint(c, c);
		if(c != '%') {
			for(; *p != '%' && *p != '\0'; p++) {
				defprint(c, *p);
				c2 = getchar();
				defprint(c, c2);
				if (c2 != *p) {
					printf("wrong format\n");
					break;
				}
			}
			p--;
			continue;

			//for (p2 = p; *p2 != '%' && *p2 != '\0'; p2++) {
			//	defprint(c, *p2);
			//	c2 = getchar();
			//	defprint(c, c2);
			//	if (c2 != *p2) {
			//		printf("wrong format\n");
			//		break;
			//	}
			//}
			//continue;
		}
		c = *++p;
		defprint(c, c);
		switch(c) {
		case 'd':
			ival = va_arg(pa, int *);
			scanf("%d", ival);
			defprint(d, ival);
			break;
		case 'f':
			dval = va_arg(pa, double *);
			scanf("%f", dval);
			defprint(f, dval);
			break;
		case 's':
			sval = va_arg(pa, char *);
			scanf("%s", sval);
			defprint(s, sval);
			break;
		default:
			printf("wrong argument\n");
			break;
		}

	}
}
