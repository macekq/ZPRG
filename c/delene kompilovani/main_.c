#include <stdio.h>
#include <Windows.h>
#include <conio.h>

/*
zdrojový kód a odpovídající hlavičkový soubor, který bude obsahovat funkce, které umožní převést zadanou
délku v decimetrech na kilometry, metry, centimetry a milimetry, funkci, které převede objem udaný v litrech na hektolitry,
decilitry, mililitry a funkci, která převede čas udaný v hodinách na dny, týdny, minuty a vteřiny.
*/

int prevodDelky(){

    int num;
    printf("vlozte cislo na prevod\n\n> ");
    scanf("%d", &num);
    printf("%d", num);

    int y, ch;
    system("cls");
    while (1){
        printf("VLOZTE JEDNOTKU VASI HODNOTY\n\n%c mm\n%c cm\n%c dm\n%c m\n%c km\n", y==0?62:255,y==1?62:255,y==2?62:255,y==3?62:255,y==4?62:255);
        ch = getch();

        if(ch == 72 && y>0) y--;
        else if(ch == 80 && y < 4) y++;
        
        system("cls");
        
        if(ch == 13) break;
    }

    int y1;
    while (1){
        printf("VLOZTE JEDNOTKU NA KTEROU PREVADITE\n\n%c mm\n%c cm\n%c dm\n%c m\n%c km\n", y1==0?62:255,y1==1?62:255,y1==2?62:255,y1==3?62:255,y1==4?62:255);
        ch = getch();
        
        if(ch == 72 && y1>0) y1--;
        else if(ch == 80 && y1 < 4) y1++;
        
        system("cls");
        
        if(ch == 13) break;
    }

    int devider = 1;
    if(y==4) num = 10000000;
    else for(int i = 0; i<y; i++) num*=10;
    
    if(y1==4) y1 = 10000000;
    else for(int i = 0;i<y1; i++) devider*=10;

    printf("ans --> %f", num/(float)devider);
}
int prevodyObsahu(){

    int num;
    printf("vlozte cislo na prevod\n\n> ");
    scanf("%d", &num);
    printf("%d", num);

    int y, ch;
    system("cls");
    while (1){
        printf("VLOZTE JEDNOTKU VASI HODNOTY\n\n%c ml\n%c dl\n%c l\n%c hl\n", y==0?62:255,y==1?62:255,y==2?62:255,y==3?62:255);
        ch = getch();

        if(ch == 72 && y>0) y--;
        else if(ch == 80 && y < 3) y++;
        
        system("cls");
        
        if(ch == 13) break;
    }

    int y1;
    while (1){
        printf("VLOZTE JEDNOTKU NA KTEROU PREVADITE\n\n%c ml\n%c dl\n%c l\n%c hl\n", y1==0?62:255,y1==1?62:255,y1==2?62:255,y1==3?62:255);
        ch = getch();
        
        if(ch == 72 && y1>0) y1--;
        else if(ch == 80 && y1 < 3) y1++;
        
        system("cls");
        
        if(ch == 13) break;
    }

    int devider;
    if(y1 == 2 && y == 1){
        printf("ans --> %f, if1", num/(float)10);
    }else if(y1 == 1 && y == 2){
        printf("ans --> %f", num*(float)10);
    }else{
        devider = 1;
        for(int i = 0; i<y; i++) num*=100;

        for(int i = 0;i<y1; i++) devider*=100;

        printf("ans --> %f", num/(float)devider);
    }
}
int prevodyCasu(){

    int num;
    printf("vlozte dobu na prevod\n\n> ");
    scanf("%d", &num);
    printf("%d", num);

    int y, ch;
    system("cls");
    while (1){
        printf("VLOZTE JEDNOTKU VASI HODNOTY\n\n%c sec\n%c min\n%c hod\n%c dny\n", y==0?62:255,y==1?62:255,y==2?62:255,y==3?62:255);
        ch = getch();

        if(ch == 72 && y>0) y--;
        else if(ch == 80 && y < 3) y++;
        
        system("cls");
        
        if(ch == 13) break;
    }
    int y1;
    while (1){
        printf("VLOZTE JEDNOTKU NA KTEROU PREVADITE\n\n%c sec\n%c min\n%c hod\n%c dny\n", y1==0?62:255,y1==1?62:255,y1==2?62:255,y1==3?62:255);
        ch = getch();
        
        if(ch == 72 && y1>0) y1--;
        else if(ch == 80 && y1 < 3) y1++;
        
        system("cls");
        
        if(ch == 13) break;
    }

    int devider = 1;
    if(y == 3 && y1 !=3){
        num*=24;
        for(int i = 0; i<y; i++) num*=60;

    }else for(int i = 0; i<y; i++) num*=60;

    if(y1 == 3 && y != 3){
        for(int i = 0; i<y1; i++) devider*=60;
        y1/=24;

    }else for(int i = 0;i<y1; i++) devider*=60;

    printf("ans --> %f", num/(float)devider);
}
int main(){ 
    
    prevodyCasu();

    return 0;
}