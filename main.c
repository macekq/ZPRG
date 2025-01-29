#include <stdio.h>

void moveCursor(int col, int row) {
    printf("\033[%d;%dH", row, col);
}
int main(){

    int counter = 0;
    for(int x = 0; x<24; x++){
        for(int y = 0; y<24; y++){

            moveCursor(x*10+3, y);
            printf("%c -> %d", counter, counter);

            counter++;

            if(counter>255) break;
        }
        if(counter>255) break;
    }

    moveCursor(0, 25);

    return 0;
}