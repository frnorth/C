#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declar.h"

/* dcl: parse a declarator */
void dcl(void)
{
	printf("-------dcl\n");
	int ns;

	for (ns = 0; gettoken() == '*'; )	/* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
	printf("-------dirdcl\n");
	/* is this nescessary? */
	int type;

	if (tokentype == '(') {		/* ( dcl ) */
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME)	/* variable name */
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");

	/* exer 5-20 */
	while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
		if (type == PARENS)
			strcat(out, " function returning");
		else if (type == BRACKETS){
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		} else {
			strcat(out, " function with argument type");
			while ((type = gettoken()) == NAME) {
				if ((type = gettoken()) == '*')
					strcat(out, " pointer to");
				else
					ungettoken();
				strcat(out, " ");
				strcat(out, token);
				if ((type = gettoken()) == ',')
					strcat(out, " and");
				else
					ungettoken();
			}
			if (type != ')')
				printf("error: type of function argument need be NAME\n");
			strcat(out, " returning");
		}
	/*----------*/

	/*
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else if (type == BRACKETS){
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	*/
}
