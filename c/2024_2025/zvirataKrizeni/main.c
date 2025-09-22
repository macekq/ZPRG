#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
typedef struct{
    int barva;
    int pohlavi;
    int typKoncetin;
    int pokryvTela;
} zvirata;

int main(){

    char koncetiny[5][32] = {
        "kopyto", "ptaci drap", "chodidlo", "ploutev", "kridlo"
    };
    char pokryvy[5][32] = {
        "srst", "peri", "kuze", "bodliny", "supiny"
    };

    zvirata[25]={{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}};

    //     {2, 0, 3, 4}, {0, 0, 0, 0}, {}
    // };

    for(int z = 0; z<5; z++){
        for(int y = 0; y<5; y++){
            for(int x = 0; x<5; x++){
                zvirata[0].barva = 1;
            }
        }
    }

    return 0;
}