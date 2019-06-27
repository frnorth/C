#include <stdio.h>

#define LENGTH 100

int getint(int *);

main()
{
	int i, array[LENGTH];

	for (i = 0; i < LENGTH && getint(&array[i]) != EOF; i++)
		;
	for (i = 0; i < LENGTH; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
