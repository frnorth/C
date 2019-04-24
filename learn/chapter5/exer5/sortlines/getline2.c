#include <stdio.h>
/* getline: get line into s, return length */
int getline2(char *s, int lim)
{
    int c;
    char *s0 = s;

    while (--lim  && (c = getchar()) != EOF) {
        *s++ = c;
        if (c == '\n')
            break;
    }
    *s = '\0';
    return s - s0;
}

