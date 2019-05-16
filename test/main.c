#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	double x;
	char *c="Hello World!";

	for(i=0;i<10;i++){
		printf("%c",c[i]);
	}
	printf("\n");
	for(x = 0.6569681; x <= 0.6569682; x += 0.0000000001 )
		printf("%.10f: %.10f\n", x, x*x*x + x*x + 5*x - 4);
	return 0;
}
