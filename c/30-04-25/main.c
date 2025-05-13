#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <conio.h>

int main(int argc, char *argv[]){
    char string[255];

    // _chdir("data");

    printf("1.: %s\n", argv[1]);
    FILE *file = fopen(argv[1], "r");
    if(file){

        fgets(string, 255, file);
        printf("%s\n", string);
        fgets(string, 255, file);
        printf("%s\n\n", string);
    
    }else printf("soubor %s nebyl nalezen\n", argv[1]);
    printf("\n---------------\n");
    
    printf("2.: %s\n", argv[2]);
    file = fopen(argv[2], "r");
    if(file){
        fgets(string, 255, file);
        printf("%s\n\n", string);
    
    }else printf("soubor %s nebyl nalezen\n", argv[2]);
    getch();

    return 0;
}