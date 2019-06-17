#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tnode.h"

#define MAXWORD 100
#define defprint(type, x) printf(#x ": %" #type"\n", x)

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("need one parameter\n");
		return -1;
	}

	int cmplen;
	struct tnode *root;
	char word[MAXWORD];

	cmplen = atoi(argv[1]);
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word, cmplen);
	treeprint(root);
	return 0;
}

