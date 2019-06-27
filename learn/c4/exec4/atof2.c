#include <ctype.h>
#include <stdio.h>

double atof2(char s[])
{
	double val, power;
	int i, sign, signe,vale;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + s[i] - '0';
	if (s[i] == '.')
		s[i++];
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + s[i] - '0';
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	else
		return sign * val / power;
	signe = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (vale = 0; isdigit(s[i]); i++)
		vale = 10 * vale + s[i] - '0';
	printf("%d\n", vale);
	if (signe > 0)
		for (i = 0; i < vale; i++)
			power /= 10;
	else
		for (i = 0; i < vale; i++)
			power *= 10;
	return sign * val / power;
}

