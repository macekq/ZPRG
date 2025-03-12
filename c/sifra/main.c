#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
char POLE[4][8] = {
    {'a','b','c','d','e','f','g'},
    {'h','i','j','k','l','m','n'},
    {'o','p','q','r','s','t','u'},
    {'v','w','x','y','z','-','&'}
};
int findIndex(char ch, int xy){

    for(int y = 0; y<4; y++){
        for(int x = 0; x<7; x++){

            if(POLE[y][x] == ch) return xy ? x : y;
        }
    }
    exit(1);
}
int output[256];
void sifrovat(){

    int tf = 0;
    do{
        printf("sifrovat: 1\nrozsifrovat: 0\n");
        tf = getch()-48;
        system("cls");
        if(tf==0||tf==1) break;
    }while(1);

    char input[256];
    printf("vlozte vetu k zasifrovani\n-");
    scanf("%s", input);

    printf("\n\n");
    for(int i = 0; i<strlen(input); i++){

        if(tf){
            output[i] = POLE[(findIndex(input[i], 0)+2)%4][findIndex(input[i], 1)];
        }else{
            int index = (findIndex(input[i], 0)-2);
            if(index<0) index+=4;
            output[i] = POLE[index][findIndex(input[i], 1)];
        }
    }
}
int main(){

    setTextColor(10);

    sifrovat();
    for(int i = 0; i<256; i++) printf("%c", output[i]);

    // printf("x: %d - y: %d", findIndex(' ', 1), findIndex(' ', 0));

    return 0;
}