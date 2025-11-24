#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x(){return 7+rand()%26;}
int main(){
    srand(time(NULL));

    int pole[10] = {x(), x(), x(), x(), x(), x(), x(), x(), x(), x()};
    
    //pocet sudych?
    int counter;
    for(int i = 0; i<10 ; i++){
        printf("%d\n", pole[i]);
        if(pole[i]%2 == 0) counter++;
    }

    //alokace mista
    printf("ted budou sude:\n");
    int *sudePole = (int *)malloc(sizeof(int) * counter);
    int pocet=0;

    //vypis
    for(int i = 0; i<10; i++){
        if(pole[i]%2 == 0){
            sudePole[pocet] = pole[i];
            printf(": %d\n", sudePole[pocet]);
            pocet++;
        }
    }

    return 0;
}