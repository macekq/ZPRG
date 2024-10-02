#include <stdio.h>
#include <Windows.h>
#include <conio.h>

/*
zdrojový kód a odpovídající hlavičkový soubor, který bude obsahovat funkce, které umožní převést zadanou
délku v decimetrech na kilometry, metry, centimetry a milimetry, funkci, které převede objem udaný v litrech na hektolitry,
decilitry, mililitry a funkci, která převede čas udaný v hodinách na dny, týdny, minuty a vteřiny.
*/

int prevodDelky(){

    int num1;
    printf("vlozte cislo na prevod\n\n> ");
    scanf("%d", &num1);
    printf("%d", num1);

    int y, ch;
    system("cls");
    while (1){
        printf("%c mm\n%c cm\n%c dm\n%c m\n%c km\n", y==0?62:255,y==1?62:255,y==2?62:255,y==3?62:255,y==4?62:255);
        ch = getch();
        if(ch == 72 && y>0) y--;
        else if(ch == 80 && y < 4) y++;
        system("cls");
        if(ch == 13) break;
    }
    
}

int main(){ 
    
    prevodDelky();

    return 0;
}