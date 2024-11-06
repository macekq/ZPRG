#include <stdio.h>
#include <Windows.h>
#include <time.h>

const int pole[5][5] = {
    {0,0,0,0,0},
    {0,219,219,219,0},
    {0,219,0,219,0},
    {0,219,219,219,0},
    {0,0,0,0,0}
};
void zobrazitPole(int num){
    for(int y = 0; y<5; y++){
        for(int x = 0; x<5; x++){
            
            if(y == 4 && x == 2) printf("%d ", num);
            else if(pole[y][x] == 0) printf("- ");
            else printf("%c ", pole[y][x]);
        }
        printf("\n");
    }
}
void vytvoritMapu(int x, int y){
    
    int counter = 1;
    
    for(int Y = 0; Y<y*5; Y++){
        for(int X = 0; X<x*5; X++){
            
            if(Y%5 == 4 && X%5 == 2) printf("%d ", counter);
            else if(pole[Y%5][X%5] == 0) printf("- ");
            else printf("%c ", pole[Y%5][X%5]);
        }
    }
}
int main(){

    srand(time(NULL));
    int krtek = rand()%10;

    vytvoritMapu(3,2);

    return 0;
}