#include <stdio.h>

#define ERRCHECK(x, low, up) { \
if (x < low || x > up) { \
		printf(#x " need be in [%d, %d]\n", low, up); \
		return -1; \
	} \
}
#define ERRCHECKVOID(x, low, up) { \
if (x < low || x > up) { \
		printf(#x " need be in [%d, %d]\n", low, up); \
	} \
}


#define defprint(x) printf(#x ": %d\n", x)
#define defprints(x) printf(#x ": %s\n", x)
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int month);

main()
{
	int month, day;

	defprint(day_of_year(1993, 11, 31));
	month_day(2000,377, &month, &day);
	defprint(month);
	defprint(day);
	defprints(month_name(2));
	return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	ERRCHECK(month,1, 12);
	ERRCHECK(day,1, daytab[leap][month]);

	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	ERRCHECKVOID(yearday, 1, 365 + leap);
	defprint(daytab[leap][13]);
	defprint(daytab[leap][14]);
	defprint(daytab[leap][15]);
	defprint(daytab[leap + 1][13]);
	defprint(daytab[leap + 1][14]);
	for (i = 1; yearday > daytab[leap][i] && i < 13; i++) {
		defprint(i);
		defprint(yearday);
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
}

/* month_name: return the name of  n-th month */
char *month_name(int month)
{
	static char *month_array[] = {
		"Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};
	return *(month_array + ((month > 0 && month < 13) ? month : 0));
}
