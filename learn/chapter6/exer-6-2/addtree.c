#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tnode.h"

struct tnode *talloc(void);
char *strdup2(char *, int);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int cmplen)
{
	int cond;

	if (p == NULL) {	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word = strdup2(w, cmplen);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strncmp(w, p->word, cmplen)) == 0)
		p->count++;		/* repeated word */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w, cmplen);
	else			/* greater than into right subtree */
		p->right = addtree(p->right, w, cmplen);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(TNODESIZE);
}

char *strdup2(char *s, int cmplen)	/* make a duplicate of s */
{
	char *p;
	int len;

	len = strlen(s) > cmplen ? cmplen : strlen(s);
	p = (char *) malloc(len + 1);	/* +1 for '\0' */
	if (p != NULL)
		strncpy(p, s, len);
	return p;
}
