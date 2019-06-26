#include <stdio.h>
#include <string.h>
#include "link.h"

#define MAXLEN 100
#define DEFINE "#define"

int getword(char *, int);
struct nlist *install(char *, char *);

main()
{
	char word[MAXLEN], def[MAXLEN], val[MAXLEN];
	struct nlist *p;
	int i;

	while (getword(word, MAXLEN) != EOF) {
		if (strcmp(word, DEFINE) == 0) {
			getword(def, MAXLEN);
			getword(val, MAXLEN);
			p = install(def, val);
			defprint(s, p->name);
			defprint(s, p->defn);
		}
	}
	defprint(s, hashtab[29]->name);
	for (i = 0; i < HASHSIXE; i++) {
		printf("%d ", i);
		for (p = hashtab[i]; p != NULL; p = p->next)
			printf("%s %s\t", p->name, p->defn);
		printf("\n");
	}
	return 0;
}
