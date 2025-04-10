#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

int toSkip[16] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

int includesLetter(char *slovo, char CH){

    for(int i = 0; i<16; i++){
        
        if(toSkip[i] == 0){
            if(slovo[i] == CH){
                toSkip[i] = 1;
                return i+1;
            }
        }
    }
    return 0;
}
int isSame(char *slovo1, char *slovo2){
    for(int i = 0; i<16; i++){
        if(slovo1[i] != slovo2[i]) return 0;
    }
    return 1;
}
int main(){

    srand(time(NULL));

    const char SLOVA[10][16] = {
        "jablko","ukulele","hruska","c","hrnek","volant","tesco","pistacie","zvykacka","fialova"
    };
    const int slovaLen[10] = {
        6,7,6,1,5,6,5,8,8,7
    };
    const int slovoIndex = rand()%10;
    const char *slovo = SLOVA[slovoIndex];
    
    char userSlovo[16] = "";
    int pokusy = 12; 
    char CH;

    printf("%s\n\n", slovo);
    while(pokusy>0){
        
        for(int i = 0; i<slovaLen[slovoIndex]; i++){
            int ch;
            if(userSlovo[i] == 0) printf("_ ");
            else printf("%c ", userSlovo[i]);
        }
        printf("\npokusy: %d\n", pokusy);

        CH = getch();
        
        int isInIndex = includesLetter(slovo, CH)-1;
        if(isInIndex >= 0){

            userSlovo[isInIndex] = CH;
        }else pokusy--;
    
        if(isSame(slovo, userSlovo)){
            system("cls");
            printf("slovo: %s\nzbyle pokusy: %d\n\nvyhrali jste !!", slovo, pokusy);
        
            return 0;
        }
    }
    printf("prohral jss :(");
    

    return 0;
}