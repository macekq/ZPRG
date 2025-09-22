#include <direct.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    //vytvorit slozku
    const char *path = "/home/macura/Documents/GitHub/ZPRG/c/mkdir"; //absolutni cesta

    if(_chdir(path) == 0){
        printf("true");
    }else{
        printf("flase");
    }

    const char *fName = "tyden";
    if(_mkdir(fName) == 0){
        printf("slozka vytvorena");
    }

    char TYDEN[5][10] = {
        "pondeli", "utery", "streda", "ctvrtek", "patek"
    };
    char PREDMETY[5][32] = {
        "mech-mech-mech-fyz-anj-cej-mat",
        "zda-zda-mat-0-tev-tev-zwa-zwa",
        "kap-kap-cej-anj-zprgc-zprgc-mat",
        "zwa-zwa-zst-tvp-zstc-zstc-anj",
        "cej-zprg-mat-ops-ops-dej-fyz"
    };
    for(int i = 0; i<5; i++){
        char myPath[255];

        snprintf(myPath, sizeof(myPath), "%s\\%s", path, "tyden");

        printf("\n%s", myPath);

        _chdir(myPath);
        _mkdir(TYDEN[i]);
    
        snprintf(myPath, sizeof(myPath), "%s\\%s", myPath, TYDEN[i]);
        _chdir(myPath);

        char *fileName = TYDEN[i];
        FILE *txt = fopen(fileName, "w");
        fprintf(txt, PREDMETY[i]);

        fclose(txt);
    }


    return 0;
}
