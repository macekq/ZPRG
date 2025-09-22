#include <stdio.h>
#include <math.h>

int prvocislo(num){

    if(num == 1) return 1;

    int couter;
    
    for(int i = 1; i<=num; i++){
        if(num%i) couter++;
    }

    if(couter==2) return 1;
    return 0;
}
int kvadraticka(a, b, c){

    int toR[2] = {(-b+sqrt(b*b - 4*a*c)/2*a), (-b-sqrt(b*b - 4*a*c))};
    return toR;
}
int maxSpolecnyDelitel(num1, num2){

    if(num1 == 0 || num2 == 0) return 0;

    for(int i = num1 > num2 ? num1 : num2; i>0; i--){
        if(num1%i == 0 && num2%i == 0) return i;
    }
}
int main(){

    return 0;
}

/*
zdrojový kód a odpovídající hlavičkový soubor, který bude obsahovat funkce pro zjištění, zda je číslo prvočíslem,
funkci pro výpočet kvadratické rovnice, funkci pro zjištění největšího společného dělitele

zdrojový kód a odpovídající hlavičkový soubor, který bude obsahovat funkce, které umožní převést zadanou
délku v decimetrech na kilometry, metry, centimetry a milimetry, funkci, které převede objem udaný v litrech na hektolitry,
decilitry, mililitry a funkci, která převede čas udaný v hodinách na dny, týdny, minuty a vteřiny.
*/