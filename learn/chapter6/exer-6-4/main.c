#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tnode.h"

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
struct tnode **treetoarray(struct tnode *, struct tnode **);
int getword(char *, int);
void qsort2(struct tnode *v[], int left, int right);

/* word frequency count */
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("need one parameter\n");
		return -1;
	}

	struct tnode *root;
	char word[MAXWORD];
	struct tnode **sort;
	struct tnode **s;
	struct tnode *sort2[1000];
	struct tnode sort3[1000];
	//sort = sort2;

	/*
	defprint(d, sizeof(root));
	defprint(d, sizeof(struct tnode));
	defprint(d, sizeof(struct tnode *));
	*/

	tnodenum = 0;
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
	treeprint(root);

	/* sort by frecquency */
	defprint(d, tnodenum);
	sort = (struct tnode **) malloc (tnodenum);
	s = sort;
	defprint(d, sort);
	sort = treetoarray(root, sort);
	defprint(d, sort);
	defprint(d, sizeof(sort));
	defprint(d, sizeof(sort2));
	defprint(d, sizeof(sort3));
	/*
	while (t-- > 0)  {
		--sort;
		printf("%4d %7s\n", (*sort)->count, (*sort)->word);
	}
	*/
	qsort2(s, 0, tnodenum - 1);
	while ((--sort - s) >= 0)
		printf("%4d %7s\n", (*sort)->count, (*sort)->word);
	return 0;
}

