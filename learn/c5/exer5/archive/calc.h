
#define NUMBER '0'		/* signal that a number was found */
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VALUBLE '4'
#define EOFSTATE '5'
#define YEAH 1
#define NOP 0

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void swap(void);

int getch(void);
void ungetch(int);
void ungets(char []);
int issep(int c, int c1, int c2, int c3);
