#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moveCursor(int col, int row) {
    printf("\033[%d;%dH", row, col);
}
int main(){

    char text[] = "mamaTeNechtela";
    char sub[255];

    strcpy(sub, text+5, 3);

    printf("string: - %s", sub);

    return 0;
}