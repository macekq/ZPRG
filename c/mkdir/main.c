#include <direct.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    //vytvorit slozku
    const char *path = "C:\\Users\\l.macura.st\\Desktop\\ZPRG\\c\\mkdir";

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
    for(int i = 0; i<5; i++){
        char myPath[255];
        strcpy(myPath, path);

        printf("%s\n", TYDEN[i]);

    	printf(strcat(myPath, "\\"));
        // _chdir(strcat(path, "\\", fName));
        
        // _mkdir(TYDEN[i]);

    }


    return 0;
}
