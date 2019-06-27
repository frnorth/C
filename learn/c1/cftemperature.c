#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
main() {

	float fahr, celsius;
	int lower, upper, step;

	lower = 0 ;		/* lower limit of temperature table */
	upper = 100;	/* upper limit */
	step = 8;		/* step size */

	fahr = lower;
	printf("%9s %9s\n", "celsius", "fahr");
	while (celsius <= upper){
		fahr = celsius * (9.0/5.0) + 32.0;
		printf("%9.0f %9.1f\n", celsius,fahr);
		celsius = celsius + step;
	}

}
