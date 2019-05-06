#include <string.h>
#include <stdio.h>
#include "declar.h"

main()
{
	while (gettoken() != EOF) {		/* 1st token on line */
		printf("-------main while\n");
		strcpy(datatype, token);	/* is the datatype */
		out[0] = '\0';
		dcl();	/* parse rest of line */
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("\033[34m%s: %s %s\n\033[0m", name, out, datatype);		
	}
	return 0;
}

