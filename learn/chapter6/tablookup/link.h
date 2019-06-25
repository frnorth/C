struct nlist {		/* table entry: */
	struct nlist *next;	/* next entry in chain */
	char *name;			/* defined name */
	char *defn;			/* replacement text */
}

#define HASHSIXE 101

static struct nlist *hashtab[HASHSIXE];	/* pointer table */
