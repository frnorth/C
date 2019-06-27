
struct key {
	char *word;
	int count;
} keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"char", 0},
	{"double", 0},
	{"else", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"unsigned", 0},
	{"while", 0}
};

//#define NKEYS (sizeof keytab / sizeof(struct key))
#define NKEYS (sizeof keytab / sizeof keytab[0])

