#include <stdio.h>

float celsius(float fahr);

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
main() {

	float fahr;
	int lower, upper, step;

	lower = 0 ;		/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	fahr = lower;
	printf("%5s |%9s\n", "fahr", "celsius");
	while (fahr <= upper){
		printf("%5.0f |%9.2f\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}

	return 0;
}

float celsius(float fahr) {
	return (5.0/9.0) * (fahr-32.0);
}
