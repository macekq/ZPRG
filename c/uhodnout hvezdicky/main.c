#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

int main(){

    srand(time(NULL));

    int chyby, spravne, streak, bonus, minule;
    float limit = 5000;
    while(chyby<3){
        int hvezdicky=0;
        clock_t start = clock();

        printf("chyby: %d\nstreak: %d\nbonus: %c\nlimit: %.2fms\n\n", chyby, streak, bonus == 3 ? 't' : 'f', limit);

        for(int y = 0; y<5; y++){
            for(int x = 0; x<5; x++){

                if(rand()%4 == 0){
                    printf("# ");
                    hvezdicky++;
                }else printf("  ");
            }
            printf("\n");
        }
        // printf("%d", hvezdicky);
        int tip = getch()-48;
        double cas = (double)(clock() - start);
        // printf("\n%.2fms", cas);
        if(cas < limit){
            if(tip == hvezdicky || (hvezdicky-bonus<tip && tip<hvezdicky+bonus)){
                printf("\n\nspravne");
                spravne++;
                if(minule) streak++;
                else streak = 1;
                minule = 1;
            }else{
                chyby++;
                minule = 0;
                printf("\n\nspatne");
            }
        }else{
            printf("\n\nmoc pomalu");
            streak = 0, minule = 0;
        }
        bonus = streak >= 3 ? 3 : 0;

        getch();
        system("cls");
    }
    return 0;
}