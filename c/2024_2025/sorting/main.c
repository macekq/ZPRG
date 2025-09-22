#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int includes(int ARR[6], int var){

    for(int i = 0; i < 6; i++){
        if(ARR[i] == var) return 1;    
    }
    return 0;
}
int correct(int arr[6]){
    for(int i = 0; i<6; i++){
        if(arr[i] != i) return 0;
    }

    return 1;
}
int logArray(int arr[6]){

    printf("[%d", arr[0]);

    for(int i = 1; i<6; i++){

        printf(", %d", arr[i]);
    }
    printf("]\n");
}
int main(){
    srand(time(NULL));

    int zeroIndex = rand()%6;
    int pole[6] = {0,0,0,0,0,0};

    for(int i = 0; i<6; i++){

        if(i != zeroIndex){
         
            int num;
            do{
                num = rand()%6;
            }while(includes(pole, num));

            pole[i] = num;
        }
    }

    while(!correct(pole)){

        for(int i = 0; i<6; i++){

            if(pole[i] > pole[i + 1]){
                printf("\nkys\n");

                int kys = pole[i + 1];
                pole[i + 1] = pole[i];
                pole[i] = kys;
            
            }else break;
        }
        
        logArray(pole);
    }
    return 0;
}