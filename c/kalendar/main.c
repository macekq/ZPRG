#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

void displayKalendar(int KALENDAR[6][4], int user[2]){

    for(int y = 0; y<6; y++){
        printf("\n");
        for(int x = 0; x<4; x++){

            printf(" %d ", KALENDAR[y][x]);
            if(KALENDAR[y][x] < 10) printf(" ");
        }
        printf("\n");
        for(int i = 0; i<4; i++){
            printf((user[0] == i && user[1] == y) ? " ^  " : "    ");
        }
    }
}
int isIn(int ARR[24], int var){

    for(int i = 0; i < 24; i++){
        if(ARR[i] == var) return 1;
        
        // printf("%d - %d\n", ARR[i], var);
    }
    return 0;
}
int fillKalendar(int KALENDAR[6][4]){
    
    int used[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int index = 0;

    for(int y = 0; y<6; y++){
        for(int x = 0; x<4; x++){
            int day;

            do{
                day = rand()%24 + 1;

            }while(isIn(used, day));

            KALENDAR[y][x] = day;
            used[index] = day;
            
            index++;
        }
    }
    
    return KALENDAR[6][4];
}
int main(){

    srand(time(NULL));
    //==========================================================================================
    // kus kodu, do ktereho nezasahujte, slouzi k tomu, abychom mohli pracovat s aktualnim datem
    //==========================================================================================
    time_t s, val = 1;
    int den, mesic, rok;
    struct tm* datum;

    s = time(NULL);

    datum = localtime(&s);
    rok = datum->tm_year + 1900;

    //asi jedine dve promenne, se kterymi budete pracovat
    den = datum->tm_mday;
    mesic = datum->tm_mon + 1;

    //==========================================================================================
    // zde muze nasledovat Vas kod
    //==========================================================================================

    int KALENDAR[6][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    KALENDAR[6][4] = fillKalendar(KALENDAR);
    int user[2] = {0,0};
    int ch;
    while(ch != 13){
        system("cls");
        displayKalendar(KALENDAR, user);

        printf("ch - %d", ch);
        if(KALENDAR[user[1]][user[0]] > den) printf("\n\nzadne takove");
        
        ch = getch();

        if(ch == 75 && user[0]>0) user[0]--;
        if(ch == 77 && user[0]<4) user[0]++;
        if(ch == 72 && user[1]>0) user[1]--;
        if(ch == 80 && user[1]<6) user[1]++;
    }
    return 0;
}
