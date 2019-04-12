#define A 0
#define B 1
#define C 2

#ifndef VAL
#define VAL 1
#endif

#if VAL == A
	#define HEADFILE "a.h"
#elif VAL == B
	#define HEADFILE "b.h"
#else
	#define HEADFILE "c.h"
#endif
#include HEADFILE

