#include <stdio.h>

float procentoFunc(float X){
    while(X>=1) X--;

    return X;
}

int main(){
    
    float x = 5.2;

    x = procentoFunc(x);

    printf("x = %f", x);

    return 0;
}