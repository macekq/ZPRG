#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

void moveCursor(int col, int row) {
    printf("\033[%d;%dH", row, col);
}
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main(){

    int datum[3][2] = {
        {0,0},{0,0},{0,0}
    };
    int CH, len = 0;
    int input[6] = {0,0,0,0,0,0};
    while(CH != 13){
    
        CH = getch();
        if(CH==8 && len>0){

            moveCursor(len, 1);
            printf(" ");
            len--;
            moveCursor(len-1, 1);

        }else if(CH != 8 && len < 11){
            setTextColor(7);
            printf("%c", CH);
            len++;

            if(len == 6){
                setTextColor(8);
                printf("/");
                len++;
            }
        }
        moveCursor(0,5);
        printf("%d", len);
        moveCursor(len+1, 0);
    }
    

    return 0;
}