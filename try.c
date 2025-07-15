#include <stdio.h>

int main(){

    char *path = "/home/macura/Desktop";
    char *txt = "dada smrdi jako stare ponozky";

    _chdir(path);
    FILE *file = fopen("dadaHodneSmrdi.txt", "w");

    fprintf(file, txt);

    return 0;
}