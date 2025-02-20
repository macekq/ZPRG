#include <stdio.h>
#include <Windows.h>

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
int main() {
   
    for(int i = 0; i<15; i++){

        setTextColor(i);
        printf("zab se pizdo <3 - %d\n", i);
    }

    return 0;
}
