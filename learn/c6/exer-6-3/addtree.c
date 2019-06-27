#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tnode.h"

struct tnode *talloc(void);
char *strdup2(char *);
struct lineapr *lalloc();

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {	/* a new word has arrived */
		defprint(s,"new node");
		p = talloc();	/* make a new node */
		p->word = strdup2(w);
		p->count = 1;
		p->left = p->right =  NULL;
		p->lptr = lalloc();
		p->lptr->linenum = linenumber;
		defprint(d, p->lptr->linenum);
		p->lptr->nextone = NULL;
		p->lptr->lastone = NULL;
	} else if ((cond = strncmp(w, p->word, cmplen)) == 0) {
		defprint(s,"match node");
		p->count++;		/* repeated word */
		p->lptr->nextone = lalloc();
		p->lptr->nextone->nextone = NULL;
		p->lptr->nextone->lastone = p->lptr;
		p->lptr = p->lptr->nextone;
		p->lptr->linenum = linenumber;
	}
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w);
	else			/* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
 	struct lineapr *s;

	if (p != NULL) {
		s = p->lptr;
		treeprint(p->left);
		printf("%4d %7s  --", p->count, p->word);
		for(; s->lastone != NULL; s = s->lastone)
			;
		for(; s->nextone != NULL; s = s->nextone)
			printf("%4d", s->linenum);
		printf("%4d\n", s->linenum);
		treeprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(TNODESIZE);
}

char *strdup2(char *s)	/* make a duplicate of s */
{
	char *p;
	int len;

	len = strlen(s) > cmplen ? cmplen : strlen(s);
	p = (char *) malloc(len + 1);	/* +1 for '\0' */
	if (p != NULL)
		strncpy(p, s, len);
	return p;
}

struct lineapr *lalloc()
{
	return (struct lineapr *) malloc(LINEAPRSIZE);
}
