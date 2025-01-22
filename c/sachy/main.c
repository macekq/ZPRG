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
void drawBoard(){
 
    int arr[8] = {8,7,6,5,4,3,2,1};
    printf("   a b c d e f g h\n\n");
    for(int y = 0; y<8; y++){

        printf("%d ", arr[y]);
        for(int x = 0; x<8; x++){

            if(y%2 == 0){
                if(x%2 == 0) printf(" %c", 254);
                else printf(" -");
            
            }else{
                if(x%2 == 1) printf(" %c", 254);
                else printf(" -");
            }
        }
        printf("\n");
    }

    printf("\n\n1 -> pawn\n2 -> knight\n3 -> bishop\n4 -> rook\n5 -> qween\n6 -> king");
}
void drawPieces(int matrix[8][8]){

    for(int y = 0; y<8; y++){

        for(int x = 0; x<8; x++){
            
            if(matrix[y][x] != 0){
                moveCursor((x+2)*2, y+3);
                
                if(matrix[y][x] > 6){
                    setTextColor(12);
                    printf("%d", matrix[y][x]-6);
                }else{
                    setTextColor(2);
                    printf("%d", matrix[y][x]);
                } 
            }
        }
    }

    moveCursor(0,48);
}
int main(){

    int POLE[8][8] = {
        {10,8,9,11,12,9,8,10},
        {7,7,7,7,7,7,7,7},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {4,2,3,5,6,3,2,4}
    };

    drawBoard();
    drawPieces(POLE);

    return 0;
}