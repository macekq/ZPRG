#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <Windows.h>
#include <conio.h>

const char *path = "C:\\Users\\l.macura.st\\Documents\\GitHub\\ZPRG\\c\\SPmacura11-06-25";

typedef struct{
    int opravneni; char username[255]; char heslo[33];
} DATA;

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void registrace(char *fileName){
    DATA user[5];
    system("cls");

//jmeno
    setTextColor(2);
    printf("vlozte uzivatelske jmeno: ");
    setTextColor(14);
    
    scanf("%s", &user[0].username);

//heslo
    do{
        system("cls");

        setTextColor(8);
        printf("heslo nemuze obsahovat mene nez 12 a vice nez 32\n");
        setTextColor(2);
        printf("vlozte heslo: ");
        setTextColor(14);

        scanf("%s", &user[0].heslo);
    }while(strlen(user[0].heslo) < 12 || strlen(user[0].heslo) > 32);
//opravneni
    do{
        system("cls");

        setTextColor(8);
        printf("[1 admin] [2 zapisujici uzivatel] [3 ctec]\n");
        setTextColor(2);
        printf("opravneni: ");
        setTextColor(14);

        scanf("%d", &user[0].opravneni);
    }while(user[0].opravneni < 1 || user[0].opravneni > 3);

//recap
    while(1){
        system("cls");
        setTextColor(8);
        printf("[enter] - vsechno je spravne\n[ esc ] - zadat znova\n");
        setTextColor(2);
        printf("username: %s\nheslo: %s\nopravneni: %d", user[0].username, user[0].heslo, user[0].opravneni); 
        
        int CH = getch();
        if(CH == 13){

            char obsah[255];

            snprintf(obsah, sizeof(obsah), "+\n%s#%s#%d", user[0].username, user[0].heslo, user[0].opravneni);

            FILE *soubor = fopen(fileName, "a");
            fprintf(soubor, obsah);

            break;
        }else if(CH == 27){
            registrace(fileName);
            break;    
        };
    }
}
int login(char *fileName){
    system("cls");

    FILE *soubor = fopen(fileName, "r");
    char buffer[1024];
    
    int counter;
    while(1){
        counter++;
        fgets(buffer, sizeof(buffer), soubor);
        // printf("%s\n%d\n%c", buffer, strlen(buffer)-1, buffer[0]);
        if(buffer[strlen(buffer)-2] != '+') break;
    }

    char **USERS = (char **)malloc(sizeof(char *) * counter);
    for(int i = 0; i<counter; i++){
        USERS[i] = (char *)malloc(sizeof(char) * 255);
    }
    for(int i = 0; i<counter; i++){
        fgets(buffer, sizeof(buffer),  soubor);
        if(buffer[strlen(buffer)-2] != '+') break;
    
        int hashIndex[3] = {0,1,1};
        do{
            hashIndex[0]++;
        }while(buffer[hashIndex[0]] != '#');

        hashIndex[1] += hashIndex[0];
        do{
            hashIndex[1]++;
        }while(buffer[hashIndex[1]] != '#');

        hashIndex[2] += hashIndex[1];
        do{
            hashIndex[2]++;
        }while(buffer[hashIndex[2]] != '#');

        strncpy(USERS[i][0], &buffer[hashIndex[0]], hashIndex[1]-hashIndex[0]);
        USERS[i][0][hashIndex[1]-hashIndex[0]] = '\n';
        
        system("cls");
        printf("%s  - jmeno", USERS[i][0]);
        getch();
    }

}
int main(){

    char userPath[255], userFileName[9] = "user.txt";

    snprintf(userPath, sizeof(userPath), "%s\\%s", path, userFileName);
    _chdir(path);

    registrace(userFileName);
    login(userFileName);

    return 0;
}