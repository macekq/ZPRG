#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

void displayKone(float KONE[10][2]){

    for(int i = 0; i<10; i++){

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

    posunoutKone(KONE);
    posunoutKone(KONE);
    posunoutKone(KONE);
    posunoutKone(KONE);
    posunoutKone(KONE);

    for(int i = 0; i<10; i++){
        KONE[i][1] /= 100, KONE[i][1] += 1;

        int index = KONE[i][1] % 1;

        printf("%d -> %.2f\n", i, index);
    }

    displayKone(KONE);

    return 0;
}