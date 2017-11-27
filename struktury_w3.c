#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct struktura {
    char x[100];
    int a, b;
} str;

typedef struct struktura2 {
    int cyfr, znakow;
} strret;

strret* funkcja(str*);

int main() {
    str *st1;
    st1 = malloc(sizeof(str*));
    strcpy(st1->x, "12345znak");
    strret* x = funkcja(st1);
    printf("\n\n%x\n\n", &x);

    printf("cyfr: %d\nznakow: %d\n", x->cyfr, x->znakow);

    free(st1);
    free(x);

    printf("cyfr: %d\nznakow: %d\n", x->cyfr, x->znakow);

    //int **z;
    //**z = 5;
    //printf("----\n\n%d\n\n\n%d\n%d", **z, ***z, **z);
    return 0;
}

strret* funkcja(str *s1) {
    int i;
    strret *strR;
    strR = malloc(sizeof(strret*));
    strR->cyfr = 0;
    strR->znakow = 0;
    for(i = 0; i < strlen(s1->x); i++) {
        if(isdigit(s1->x[i]))
            strR->cyfr++;
        if(isalnum(s1->x[i]))
            strR->znakow++;
    }
    printf("%d %d\n\n%x", strR->cyfr, strR->znakow, &strR);
    return strR;
}
