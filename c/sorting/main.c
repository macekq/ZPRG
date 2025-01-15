#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int includes(int ARR[16], int var){

    for(int i = 0; i < 16; i++){
        if(ARR[i] == var) return 1;    
    }
    return 0;
}
int generateRandomArray(){

    int zeroIndex = rand()%16;
    int pole[16] = {0};

    for(int i = 0; i<16; i++){

        if(i != zeroIndex){
         
            int num;
            do{
                num = rand()%16;
            }while(includes(pole, num));

            pole[i] = num;
        }
    }

    return pole[16];
}
int main(){
    srand(time(NULL));

    int arr[16] = {0};

    arr[16] = generateRandomArray();

    for(int i = 0; i<16; i++){

        printf("%d, ", arr[i]);
    }

    return 0;
}