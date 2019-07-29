#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "link.h"

char *strdup2(char *);
Nptr lookup(char *s);
Nptr *lookup2(char *s);
unsigned hash(char *s);

/* install: put (name, defn) in hashtab */
Nptr install(char *name, char *defn)
{
	Nptr np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) { /* not found */
		np = (Nptr) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup2(name)) == NULL)
			return NULL;
		hashval = hash(name);
		defprint(d, hashval);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
		defprint(s, hashtab[hashval]->name);
	} else		/* already there */
		free((void *) np->defn);	/* free previous defn */
	if ((np->defn = strdup2(defn)) == NULL)
		return NULL;
	return np;
}

void uninstall(char *name)
{
	Nptr *p, p2;

	if ((p = lookup2(name)) != NULL) {
		free((*p)->name);
		free((*p)->defn);
		p2 = *p;
		if ((*p)->next != NULL)
			*p = (*p)->next;
		else
			*p = NULL;
		free(p2);
	}
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIXE;
}

/* lookup: look for s in hashtab */
Nptr lookup(char *s)
{
	Nptr np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;	/* found */
	return NULL;		/* not found */
}

/* lookup2: return the address of the pointer */
Nptr *lookup2(char *s)
{
	Nptr *np;

	for (np = &hashtab[hash(s)]; *np != NULL; np = &((*np)->next))
		if (strcmp(s, (*np)->name) == 0)
			return np;	/* found */
	return NULL;		/* not found */
}


char *strdup2(char *s)	/* make a duplicate of s */
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);	/* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}
