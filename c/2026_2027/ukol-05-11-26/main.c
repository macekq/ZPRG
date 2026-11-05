#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int scitaciFunkce(){

    int count = 0;
    int CH;
    int X = 1;

    while(1){
        printf("vlozte cislo: ");
        scanf("%d", &X);

        if(X <= 0) break;
        else count++;
    }
    return count;
}
int main(){

    printf("pocet spravne zadanych hodnot: %d", scitaciFunkce());

    return 0;
}