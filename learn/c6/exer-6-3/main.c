#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tnode.h"

#define MAXWORD 100

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

	struct tnode *root;
	char word[MAXWORD];

	linenumber = 1;
	cmplen = atoi(argv[1]);
	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (strcmp("\n", word) == 0)
			linenumber++;
		if (strcmp("the", word) == 0)
			continue;
		if (strcmp("and", word) == 0)
			continue;
		if (isalpha(word[0]))
			root = addtree(root, word, cmplen);
	}
	defprint(s, "get down");
	treeprint(root);
	return 0;
}

