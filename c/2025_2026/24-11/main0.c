#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main(){

    int poleZnaku[7];
    int counter;

    //user input
    printf("zacnete vkladat pismenka:\n");
    for(int i = 0; i<7; i++){
        int x = getch();
        if(x<97) counter++;

        poleZnaku[i] = x;
        printf("- %c\n", poleZnaku[i]); // -> kontrola vstupu
    }

    int *pole2 = (int *)malloc(sizeof(int) * counter);
    int j;
    
    //vypis
    for(int i = 0; i<7; i++){
        if(poleZnaku[i]>=97){
            pole2[j] = poleZnaku[i];
            printf("%c\n", pole2[j]);
            j++;
        }
    }

    return 0;
}