#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for*/

/* find all lines matching pattern */
main()
{
	char line[MAXLINE];
	int found = 0, index = 0;

	while (getline2(line, MAXLINE) > 0) {
		if ((index = strindex(line, pattern)) >= 0) {
			printf("%d %s", index, line);
			found++;
		}
		else
			printf("%d\n", index);
	}
	return found;
}
