struct nlist {		/* table entry: */
	struct nlist *next;	/* next entry in chain */
	char *name;			/* defined name */
	char *defn;			/* replacement text */
};

#define HASHSIXE 101
#define defprint(type, x) printf(#x ": \033[33m%" #type "\033[0m\n", x)

//static struct nlist *hashtab[HASHSIXE];	/* pointer table */
struct nlist *hashtab[HASHSIXE];	/* pointer table */
