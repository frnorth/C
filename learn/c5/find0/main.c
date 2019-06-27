#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline2(char *s, int lim);

main(int argc, char *argv[])
{
	int x = 0, n = 0, found = 0, linenum = 0, c;
	char line[MAXLINE];

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch(c){
			case 'x':
				x = 1;
				break;
			case 'n':
				n = 1;
				break;
			default:
				printf("Maybe wrong parameter.\n");
				argc = 0;
				found = -1;
				break;
			}
	if (argc != 1)
		printf("Maybe wrong partten\n");
	else
		while (getline2(line, MAXLINE) > 0) {
			linenum++;
			if ((strstr(line, *argv) != NULL) != x) {
				found++;
				if (n == 1)
					printf("%d: ", linenum);
				printf("%s", line);
			}
		}
	return found;
}
