#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
void ungettoken(); /* ungettoken for exer 5-20 */
void ungettoken2(char *p); /* ungettoken2 for exer 5-20 */
int tokentype;			/* type of last token */
char token[MAXTOKEN];	/* last token string */
char name[MAXTOKEN];	/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc. */
char out[1000];
