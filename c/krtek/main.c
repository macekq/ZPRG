#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

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
void vytvoritMapu(int x, int y, int krtek){
    
    int counter = 1, krtekCounter = 1;
    
    for(int Y = 0; Y<y*5; Y++){
        for(int X = 0; X<x*5; X++){
            
            if(Y%5 == 2 && X%5 == 2 && krtek != 0){
                if(krtekCounter == krtek) printf("# ");
                else printf("- ");
                krtekCounter++;
            }
            else if(Y%5 == 4 && X%5 == 2){
                printf("%d ", counter);
                counter++;

            }else if(pole[Y%5][X%5] == 0) printf("- ");
            else printf("%c ", pole[Y%5][X%5]);
        }
        printf("\n");
    }
}

int main(){

    srand(time(NULL));
    
    // printf("vlozte velikost pole (na vysko a na sirku) -> ");
    // int velikostPole = getch()-48;
    // system("cls");

    while(1){
        int krtek = rand()%9 + 1;

        clock_t start = clock();
        vytvoritMapu(3,3,krtek);

        int loc;
        do{
            loc = getch();
            if(loc-48!=krtek) printf("\n\n* tesne vedle *");
        }while(loc - 48 != krtek);

        system("cls");
        double reakce = (double)(clock() - start);
        printf("\nreakce: %.2fms\n", reakce);
    }
    return 0;
}