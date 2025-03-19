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
    srand(time(NULL));

    //vyer velikosti
    int CH, size = 2;
    do{
        moveCursor(0,0);
        printf("= = = = = =\n%d \n[enter]pro pokracovani", size);
        moveCursor(size-1, 0);
        printf("#");

        CH = getch();
        if(CH==77 && size<12) size+=2;
        else if(CH==75 && size>2) size-=2;

    }while (CH!=13);
    system("cls");
    moveCursor(0,0);
    
    //vytvorit 2d pole
    int **POLE = (int **)malloc(sizeof(int *) * size);

    for(int i = 0; i<size; i++){
        POLE[i] = (int *)malloc(sizeof(int) * size);
    }

    for(int y = 0; y<size; y++){
        for(int x = 0; x<size; x++){

            printf(" %c", 254);
        }
        printf("\n");
    }

    

    return 0;
}