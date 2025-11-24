#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int pole[20];
    int kladneCisla, zaporneCisla;

    //user input
    for(int i = 0; i<20; i++){
        
        int cislo;
        printf("cislo - ");
        scanf("%d", &cislo);
        
        pole[i] = cislo;

        //delky vyslednych poli
        if(cislo >= 0) kladneCisla;
        else zaporneCisla;
    }

    //deklarace poli
    int *zapPole = (int *)malloc(sizeof(int) * zaporneCisla);
    int *kladPole = (int *)malloc(sizeof(int) * kladneCisla);

    int zapIndex, kladIndex;

    //trizeni pole do dvou
    for(int j = 0; j<20; j++){
        
        if(pole[j] >= 0){
            kladPole[kladIndex] = pole[j];
            kladIndex++;
        }else{
            zapPole[zapIndex] = pole[j];
            zapIndex++;
        }
    }
    
    //vypis
    printf("\n\nZAPORNA CISLA:\n");
    for(int x = 0; x<zapIndex; x++){
        printf("%d\n", zapPole[x]);
    }
    printf("\n\nKLADNA CISLA:\n");
    for(int x = 0; x<kladIndex; x++){
        printf("%d\n", kladPole[x]);
    }
    
    return 0;
}