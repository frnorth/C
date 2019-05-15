
#define MAXWORD 100
#define NKEYS 9

struct key {
	char *word;
	int count;
} keytab[] = {
	("auto", 0),
	("break", 0),
	("char", 0),
	("double", 0),
	("else", 0),
	("goto", 0),
	("if", 0),
	("unsigned", 0),
	("while", 0)
}

int getword(char *, int);
int binsearch(char *, struct key *, int);

