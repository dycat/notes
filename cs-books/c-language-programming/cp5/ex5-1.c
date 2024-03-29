/*
    ex 1 As written, getint treats a + or - not followed by digit as valid representation of zero. 
    Fix it to push such a character back on the input.
*/
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int main() {
    
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0; isdigit(c), c = getch(); pn++) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
    
}