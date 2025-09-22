#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

char charArr[] = "!#$%&()*+-/0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void moveCursor(int col, int row) {
    printf("\033[%d;%dH", row, col);
}
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
int getIndex(char ch){
    for(int i = 0; i<80; i++){
        if(charArr[i] == ch) return i;
    }
    return 0;
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
            POLE[y][x] = 0;
        }
    }

    int **charPOLE = (int **)malloc(sizeof(int *) * size);

    for(int i = 0; i<size; i++){
        charPOLE[i] = (int *)malloc(sizeof(int) * size);
    }
    for(int y = 0; y<size; y++){
        for(int x = 0; x<size; x++){
            charPOLE[y][x] = 0;
        }
    }

    //vytisknout 2d pole a vytvorit pary
    int **par1 = (int **)malloc(sizeof(int *) * (size*size/2));
    int **par2 = (int **)malloc(sizeof(int *) * (size*size/2));
    for(int i = 0; i<size*size/2; i++){
        par1[i] = (int *)malloc(sizeof(int) * 2);
        par2[i] = (int *)malloc(sizeof(int) * 2);
    }
    for(int y = 0; y<size*size/2; y++){
        par1[y][0] = 0, par1[y][1] = 0;
        par2[y][0] = 0, par2[y][1] = 0;
    }

    int *uncovered = (int *)malloc(sizeof(int) * (size*size/2));
    for(int i = 0; i<size*size/2; i++) uncovered[i] = -1;
    
    int par1counter = 0, par2counter = 0, uncCount = 0;

    int counter;
    for(int y = 0; y<size; y++){
        for(int x = 0; x<size; x++){
            
            if((rand()%2 && par1counter<size*size/2) || (par2counter+1>size*size/2)){
                
                // setTextColor(1);
                par1[par1counter][0] = x;
                par1[par1counter][1] = y;
                par1counter++;
            }else{
                
                // setTextColor(2);
                par2[par2counter][0] = x;
                par2[par2counter][1] = y;
                par2counter++;
            }
            counter++;
            
            printf("%c ", 254/*POLE[y][x]*/);
        }
        printf("\n");
    }

    for(int i = 0; i<size*size/2; i++){
        
        charPOLE[par1[i][1]][par1[i][0]] = charArr[i];
        charPOLE[par2[i][1]][par2[i][0]] = charArr[i];
    }
    
    int input, X = 0, Y = 0, lastX = 0, lastY = 0;
    int selected[2] = {-1,-1};
    while(input!=27){
        input = getch();
        switch(input){
            case 72://w
                if(Y>0) Y--;
                break;
            case 80://s
                if(Y<size-1) Y++;
                break;
            case 75://a
                if(X>0) X--;
                break;
            case 77://d
                if(X<size-1) X++;
                break;
            case 13://enter

                if(selected[0] != -1 && charPOLE[Y][X] == charPOLE[selected[1]][selected[0]]){
                    
                    uncovered[uncCount] = getIndex(charPOLE[Y][X]);
                    uncCount++;

                    setTextColor(2);
                    moveCursor(0,20);
                    printf("true");
                }

                setTextColor(7);
                moveCursor(selected[0]*2+1, selected[1]+1);
                printf("%c", 254);

                selected[0] = X, selected[1] = Y;
                break;
        }
        if(X != lastX || Y != lastY){
            setTextColor(7);
            moveCursor(lastX*2+1, lastY+1);
            printf("%c", 254);
        }

        setTextColor(4);
        moveCursor(X*2+1, Y+1);
        printf("%c", charPOLE[Y][X]);

        if(selected[0] != -1){
            setTextColor(4);
            moveCursor(selected[0]*2+1, selected[1]+1);
            printf("%c", 254);
        }
        for(int i = 0; i<uncCount; i++){

            if(par1[uncovered[i]][0]==X&&par1[uncovered[i]][1]==Y) setTextColor(4);
            else setTextColor(2);
            
            moveCursor(par1[uncovered[i]][0]*2+1, par1[uncovered[i]][1]+1);
            printf("%c", charPOLE[par1[uncovered[i]][1]][par1[uncovered[i]][0]]);

            if(par2[uncovered[i]][0]==X&&par2[uncovered[i]][1]==Y) setTextColor(4);
            else setTextColor(2);

            moveCursor(par2[uncovered[i]][0]*2+1, par2[uncovered[i]][1]+1);
            printf("%c", charPOLE[par2[uncovered[i]][1]][par2[uncovered[i]][0]]);
        }
        setTextColor(8);
        moveCursor(0, 16);
        printf("%d - %d\n", X, Y);

        lastX = X, lastY = Y;

        if(uncCount==size*size/2) break;
    }
    system("cls");
    moveCursor(0,0);
    printf("dokazal si to!!");
    
    /*
    for(int i = 0; i<80; i++){
        printf("%d -> %c\n", i, charArr[i]);
    }
    */

    return 0;
}
