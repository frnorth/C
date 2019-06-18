struct tnode {		/* the tree node */
	char *word;		/* points to the text */
	int count;		/* number of occurrences */
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
	struct lineapr *lptr;
};

struct lineapr {
	struct lineapr *nextone;
	struct lineapr *lastone;
	int linenum;
};

#define TNODESIZE sizeof(struct tnode)
#define LINEAPRSIZE sizeof(struct lineapr)

#define defprint(type, x) printf(#x ": %" #type"\n", x)

int tnodenum;
int cmplen;
int linenumber;

