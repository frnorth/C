#include <string.h>
#include <stdio.h>
#include "declar.h"

main()
{
	int type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				/* exer 5-19 */
				if (gettoken() == NAME)
					sprintf(temp, "*%s", out);
				else
					sprintf(temp, "(*%s)", out);
				ungettoken();
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %a\n", token);
		printf("\033[34m%s\n\033[0m", out);
	}
	return 0;
}

