#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

typedef struct{
    int id;
    int cena;
    char vyrobce[255];
    char model[255];
    char datumVyroby[255];
} MOBIL;

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main(){

    char znacky[5][64] = {
        "apple", "samsung", "aligator", "nothing", "david"
    };
    char model[5][64] = {
        "iphone 13", "S22", "X10S", "cmf phone 2", "mastny" 
    };
    
    MOBIL mobily[6] = {
        {0,12000,"apple","iphone 13","13.03.2024"},
        {1,16000,"samsung","s20","23.05.2018"},
        {2,1200,"aligator","XS1820","01.01.2011"},
        {3,5000,"nothing-cmf","phone 1","01.03.2022"},
        {4,25000,"LG","wing","04.03.2024"},
        {5,80,"nokia","3310","11.02.1968"}
    };

    setTextColor(8);
    for(int i = 0; i<6; i++){
        printf("id: %d\ncena: %dkc\nvyrobce: %s\nmodel %s\ndatum vyroby: %s\n\n",i, mobily[i].cena, mobily[i].vyrobce, mobily[i].model, mobily[i].datumVyroby);
    }

    setTextColor(2);
    printf("seradit podle:\n[1]:cena\n[2]:vyrobce\n[3]:datum vyroby\n\n");
    setTextColor(7);

    switch(getch()-48){
        case 1:
            // bubble sort
            int idArr[6] = {0,1,2,3,4,5};
            int cena[6] = {mobily[0].cena, mobily[1].cena, mobily[2].cena, mobily[3].cena, mobily[4].cena, mobily[5].cena};

            for (int step = 0; step < 6 - 1; ++step) {
                
                for (int i = 0; i < 6 - step - 1; ++i) {
                
                    if (cena[i] > cena[i + 1]) {
                        
                        int temp = cena[i];
                        cena[i] = cena[i + 1];
                        cena[i + 1] = temp;
                    
                        int temp2 = idArr[i];
                        idArr[i] = idArr[i + 1];
                        idArr[i + 1] = temp2;
                    }
                }
            }
            setTextColor(4);
            for(int i = 0; i<6; i++){
                printf("%d - %d - %s\n", i, cena[i], mobily[idArr[i]].vyrobce);
            }
            break;            
    }

    return 0;
}