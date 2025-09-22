#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

void moveCursor(int col, int row) {
    printf("\033[%d;%dH", row, col);
}

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void clearRect(int x, int y, int width, int height){

    for(int j = 0; j<height; j++){
        moveCursor(x, y+j);
        for(int i = 0; i<width; i++){
            printf(" ");
        }
    }
}

int main(){

    int lenght;
    printf("vlozte delku matice -> ");
    scanf("%2d", & lenght);

    printf("len -> %d", lenght);
    getch();
    clearRect(0,0,50,1);
    moveCursor(0,0);

    int MATICE[lenght][lenght] = {{0}};

    return 0;
}