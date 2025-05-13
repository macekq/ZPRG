#include <stdio.h>
#include <stdlib.h>

int main(){

    struct pokus{
        char pismeno;
        // char *text;
        int cislo;
    };
    
    struct pokus s1;
    
    s1.pismeno = '#';
    s1.cislo = 12;

    printf("%c\n\n", s1.pismeno);
    printf("%d\n\n", s1.cislo);

    return 0;
}