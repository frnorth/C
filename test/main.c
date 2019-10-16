#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main()
{
	int i;
	double x, y;
	char *c="Hello World!";

	for ( x = 0; x < 100; x++) {
		y = 100 * exp(-pow(pow((x - 50) / 10, 2.0), 1.0));
		printf("%f\n", y);
	}


	//for(i=0;i<10;i++){
	//	printf("%c",c[i]);
	//}
	//printf("\n");
	//for(x = 0.6569681; x <= 0.6569682; x += 0.0000000001 )
	//	printf("%.10f: %.10f\n", x, x*x*x + x*x + 5*x - 4);
	return 0;
}
