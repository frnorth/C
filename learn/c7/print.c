#include <stdio.h>

main()
{
	printf("%-20s\n", "Hello World!");
	printf("%20s\n", "Hello World!");
	printf("%x %o  % \n", 15, 15);
	printf("%.*s\n", 16, "Hello World!");
	printf("%.*s\n", 16, "abcdefghijklmn");
	printf("%*s\n", 16, "abcdefghijklmn");
	printf("Hello World!%c", 8); //backspace(删除)字符的 ASCII 码是 8
}
