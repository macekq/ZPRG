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

    //vytisknout 2d pole a vytvorit pary
    int **par1 = (int **)malloc(sizeof(int *) * (size*size/2));
    int **par2 = (int **)malloc(sizeof(int *) * (size*size/2));
    for(int i = 0; i<size*size/2; i++){
        par1[i] = (int *)malloc(sizeof(int) * 2);
        par2[i] = (int *)malloc(sizeof(int) * 2);
    }
    int par1counter, par2counter;
    int charList = (int *)malloc(sizeof(int) * (size*size/2));

    int counter;
    for(int y = 0; y<size; y++){
        for(int x = 0; x<size; x++){

            if(rand()%2){
                par1[par1counter][0] = x;
                par1[par1counter][1] = y;
                par1counter++;
            }else{
                par2[par2counter][0] = x;
                par2[par2counter][1] = y;
                par2counter++;
            }
            counter++;
            printf(" %c", 254);
        }
        printf("\n");
    }

    return 0;
}