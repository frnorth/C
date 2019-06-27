#include <stdio.h>

#define LENGTH 100

int getfloat(double *);

main()
{
	int i, j;
	double array[LENGTH];

	for (i = 0; i < LENGTH && getfloat(&array[i]) != EOF; i++)
		;
	for (j = 0; j < i; j++)
		printf("%f ", array[j]);
	printf("\n");
	return 0;
}
