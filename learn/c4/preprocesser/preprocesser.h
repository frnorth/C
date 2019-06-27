#define A 0
#define B 1
#define C 2

#ifndef VAL
#define VAL 1
#endif

//#if A < sizeof(int) /* ... A sizeof can not be used in a #if line, because the preprocessor does not parse type names. */
#if VAL == A
	#define HEADFILE "a.h"
#elif VAL == B
	#define HEADFILE "b.h"
#else
	#define HEADFILE "c.h"
#endif
#include HEADFILE

