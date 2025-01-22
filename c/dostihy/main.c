#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

void displayKone(float KONE[10][2]){

    for(int i = 0; i<10; i++){

        printf("%d", i);
        for(int j = 0; j <= KONE[i][0]; j++) printf("%c", 255);
        printf("%c\n", 254);
    }
}
float posunoutKone(float KONE[10][2]){

    for(int i = 0; i<10; i++){

        KONE[i][0] += KONE[i][1];
    }

    return KONE[10][2];
}
int pokracovat(float KONE[10][2]){

    for(int i = 0; i<10; i++){

        if(KONE[i][0] >= 80) return 0;
    }
    return 1;
}
int main(){

    srand(time(NULL));

    float KONE[10][2] = {
        {0, rand()%100},
        {0, rand()%100},
        {0, rand()%100},
        {0, rand()%100},
        {0, rand()%100},
        {0, rand()%100},
        {0, rand()%100},
        {0, rand()%100},
        {0, rand()%100},
        {0, rand()%100}
    };
    
    for(int i = 0; i<10; i++) KONE[i][1] /= 100, KONE[i][1] += 1;

    printf("kdo vyhraje? [0-9]: ");
    int tip = getch() -48;

    while(pokracovat(KONE)){

        system("cls");

        displayKone(KONE);
        KONE[10][2] = posunoutKone(KONE);

        Sleep(100);
    }

    int vyherce;
    for(int i = 0; i<10; i++){git
        if(KONE[i][0] >= 80) vyherce = i;
    }

    printf("\n\ntip -> %d, vyherce -> %d", tip, vyherce);
    printf(vyherce == tip ? "\n\nneni to gamble kdyz vis ze vyhrajes" : "\n\ntezce si prodelal a manzelka te opustila :(");
    return 0;
}
