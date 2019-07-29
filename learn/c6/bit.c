#include <stdio.h>

struct {
	unsigned int is_keyword : 1;
	unsigned int is_extern : 1;
	unsigned int is_static : 1;
} flags;

main()
{
	flags.is_keyword = 1;
	printf("%d\n", (flags.is_keyword));
}
