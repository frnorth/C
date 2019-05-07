#include <string.h>
#include <stdio.h>
#include "declar.h"

main()
{
	int c;
	char temp[MAXTOKEN];

	while (gettoken() != EOF) {		/* 1st token on line */
		printf("-------main while\n");
		strcpy(datatype, token);	/* is the datatype */

		/* this is for exer 5-20 */
		while (gettoken() == NAME) {
			strcat(datatype, " ");
			strcpy(temp, token);
			if (gettoken() != NAME)
				break;
			ungettoken();
			strcat(datatype, temp);
		}
		ungettoken();
		ungettoken2(temp);
		temp[0] = '\0';
		/* ----------------------*/

		out[0] = '\0';
		dcl();	/* parse rest of line */
		if (tokentype != '\n') {
			printf("syntax error\n");
			/* exer 5-18 */
			while ((c = getch()) != '\n' && c != EOF)
				;
		}
		printf("\033[34m%s: %s %s\n\033[0m", name, out, datatype);		
	}
	return 0;
}

