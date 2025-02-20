#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

//dodelat legal pohyby figurek

const char abc[] = "abcdefgh";
const int revInt[] = {7,6,5,4,3,2,1,0};
int removedPieces[32] = {0};
int removedPiecesSize;

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

void moveCursor(int col, int row) {
    printf("\033[%d;%dH", row, col);
}
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void drawBoard(){
 
    const int arr[8] = {8,7,6,5,4,3,2,1};
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
void push(int value) {

    removedPieces[removedPiecesSize] = value;
    removedPiecesSize++;
}
int charNaSouradnice(char AazH){

    for(int i = 0; i<8; i++){
        if(AazH == abc[i]) return i;
    }
    return 0;
}
int validStart(char pos[3], int tah){

    int valid[2] = {0,0}, souradnice[2] = {charNaSouradnice(pos[0]), revInt[pos[1]-49]};
    moveCursor(0,50);
    printf("%d - %d", souradnice[0], souradnice[1]);
    moveCursor(0,48);
    printf("%c - %c", pos[0], pos[1]);

    for(int i = 0; i<8; i++){

        if(abc[i] == pos[0]) valid[0] = 1;
        if(i+48 == pos[1]) valid[1] = 1;

        if(tah){
            if(POLE[souradnice[1]][souradnice[0]] >= 7 || POLE[souradnice[1]][souradnice[0]] == 0) return 0;
        }else{
            if(POLE[souradnice[1]][souradnice[0]] < 7) return 0;
        }
    }
    moveCursor(0,47);
    printf("%d - %d <3", valid[0], valid[1]);

    return valid[0] && valid[1];
}
int validDest(char souradnice[2][3], int tah){
    if(souradnice[1][0] < 8 && souradnice[1][0] >= 0) return 0;
    
    if(tah && POLE[souradnice[1][1]][souradnice[1][0]] != 0){
    
        if(POLE[souradnice[1][1]][souradnice[1][0]] < 7) return 0;
    }else{
    
        if(POLE[souradnice[1][1]][souradnice[1][0]] >= 7) return 0;
    }

    switch(POLE[souradnice[0][1]][souradnice[0][0]] - (POLE[souradnice[0][1]][souradnice[0][0]] > 7 ? 6 : 0)){

        case 1:{
            if(souradnice[0][1] == 6 && (souradnice[1][1] == 4 || souradnice[1][1] == 5) && souradnice[0][0] == souradnice[1][0]) return 1;
            else{

                if(souradnice[0][0] == souradnice[1][0] && souradnice[0][1]+1 == souradnice[1][1] && POLE[souradnice[1][1]][souradnice[1][0]] == 0) return 1;
                if((souradnice[0][0]+1 == souradnice[1][0] || souradnice[0][0]-1 == souradnice[1][0]) && souradnice[0][1]+1 == souradnice[1][1] && POLE[souradnice[1][1]][souradnice[1][0]] > 6) return 1;

            }
            return 0;
        }
        case 2:{
            int legalKnightMoves[8][2] = {
                {-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}
            };
            for(int i = 0; i<8; i++){
                if(souradnice[0][0] + legalKnightMoves[i][0] == souradnice[1][0] && souradnice[0][1] + legalKnightMoves[i][1] == souradnice[1][1]) return 1;
            }
            return 0;
        }
        case 3:{
            for(int i = 1; i<8; i++){
                
                if(
                    souradnice[0][0] + i == souradnice[1][0] && souradnice[0][1] + i == souradnice[1][1] ||
                    souradnice[0][0] + i == souradnice[1][0] && souradnice[0][1] - i == souradnice[1][1] ||
                    souradnice[0][0] - i == souradnice[1][0] && souradnice[0][1] + i == souradnice[1][1] ||
                    souradnice[0][0] - i == souradnice[1][0] && souradnice[0][1] - i == souradnice[1][1]
                )
            }
        }
        default:{
            return 0;
        }
    }
}
void clearRect(int x, int y, int width, int height){

    for(int j = 0; j<height; j++){
        moveCursor(x, y+j);
        for(int i = 0; i<width; i++){
            printf(" ");
        }
    }
}
void drawPieces(){

    for(int y = 0; y<8; y++){

        for(int x = 0; x<8; x++){
            
            if(POLE[y][x] != 0){
                moveCursor((x+2)*2, y+3);
                
                if(POLE[y][x] > 6){
                    setTextColor(12);
                    printf("%d", POLE[y][x]-6);
                }else{
                    setTextColor(2);
                    printf("%d", POLE[y][x]);
                } 
            }
        }
    }

    moveCursor(0,24);
}
void movePiece(int currX, int currY, int destX, int destY, int tah){

    int piece;
    piece = POLE[currY][currX];

    POLE[currY][currX] = 0;
    POLE[destY][destX] = piece;

    moveCursor((currX+2)*2, currY+3);
    
    if(currY%2 == 0){
        if(currX%2 == 0) printf("%c", 254);
        else printf("-");
    }else{
        if(currX%2 == 1) printf("%c", 254);
        else printf("-");
    }

    if(POLE[destY][destX] == 0){
        push(POLE[destY][destX]);
    }
    POLE[destY][destX] = piece;

    setTextColor(tah ? 12 : 2);
    moveCursor((destX+2)*2, destY+3);
    printf("%d", (piece > 6 ? piece-6 : piece));
}
int main(){

    drawBoard();
    system("cls");
    drawBoard();
    drawPieces();

    char souradnice[2][3];
    int tah = 1;
    
    while(1){

        clearRect(0, 23, 100, 5);

        if(tah){
            setTextColor(8);
            moveCursor(0,23);
            printf("bily na tahu");
            do{
                clearRect(0,25,100,1);
                moveCursor(0,25);
                setTextColor(8);
                printf("vlozte souradnici figurky s kterou chcete pohnout - ");
                setTextColor(7);
                scanf("%2s", souradnice[0]);
            
            }while(!validStart(souradnice[0], 1));
            do{
                clearRect(0,25,100,1);
                moveCursor(0,25);
                setTextColor(8);            
                printf("vlozte souradnice na ktere chcete figurku presunout - ");
                setTextColor(7);
                scanf("%2s", souradnice[1]);

            }while(0);
            
            tah = 0;
        }else{
            setTextColor(8);
            moveCursor(0,23);
            printf("cerny na tahu");
            do{
                clearRect(0,25,100,1);
                setTextColor(8);
                moveCursor(0,25);
                printf("vlozte souradnici figurky s kterou chcete pohnout - ");
                setTextColor(7);
                scanf("%2s", souradnice[0]);

            }while(!validStart(souradnice[0], 0));
            do{                
                clearRect(0,25,100,1);
                moveCursor(0,25);
                setTextColor(8);            
                printf("vlozte souradnice na ktere chcete figurku presunout - ");
                setTextColor(7);
                scanf("%2s", souradnice[1]);
            
            }while(0);
            
            tah = 1;
        }
        souradnice[0][0] = charNaSouradnice(souradnice[0][0]);
        souradnice[0][1] = revInt[souradnice[0][1]-49];
        souradnice[1][0] = charNaSouradnice(souradnice[1][0]);
        souradnice[1][1] = revInt[souradnice[1][1]-49];

        movePiece(souradnice[0][0], souradnice[0][1], souradnice[1][0], souradnice[1][1], tah);
    }
    
    return 0;
}