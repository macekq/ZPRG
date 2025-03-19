#include <stdio.h>

int main(){

    int input;
    while(input!=27){
        input = getch();
        printf("%d\n", input);
        if(input == 77) printf("?huh?");
        if(input == 224) printf("?huh?");
    }

    return 0;
}