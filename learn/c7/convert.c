#include <stdio.h>
#include <ctype.h>

void io(int (*towhat)(int));

int main (int argc, char *argv[])
{
	if (argc != 1)
		return -1;
	if (strcmp(argv[0], "./upper") == 0)
		io(toupper); 
	else if (strcmp(argv[0], "./lower") == 0)
		io(tolower);
	else {
		printf("exe name need to be upper or lower\n");
		return -1;
	}
	return 0;
}

void io(int (*towhat)(int))
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(towhat(c));
}
