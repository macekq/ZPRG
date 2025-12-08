#include <stdio.h>
#include <stdlib.h>

void pokus(int* a, int* b, int* c){
    *c = 5;
    *a = 9;
    *b = 1;
}

int main(){

    int A = 0, B = 0, C = 0;

    pokus(&A, &B, &C);
    printf("a: %d\nb: %d\nc: %d", A, B, C);

}