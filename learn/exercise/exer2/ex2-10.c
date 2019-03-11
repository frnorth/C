#include <stdio.h>

main(){
	int c;

	while ((c = getchar()) != EOF) {
		c += (c >= 'A' && c <= 'Z') ? 'a' - 'A' : 0;
		putchar(c);
	}
}
