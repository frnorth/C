#include <stdio.h>
#include <string.h>
#include "link.h"

#define MAXLEN 100
#define DEFINE "#define"
#define UNDEF "#undef"

int getword(char *, int);
struct nlist *install(char *, char *);
void uninstall(char *);

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
		} else if (strcmp(word, UNDEF) == 0) {
			getword(def, MAXLEN);
			uninstall(def);
		}
	}
	for (i = 0; i < HASHSIXE; i++) {
		printf("%d ", i);
		for (p = hashtab[i]; p != NULL; p = p->next)
			printf("%s %s\t", p->name, p->defn);
		printf("\n");
	}
	return 0;
}
