#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <Windows.h>
// #include <conio.h>
#include <string.h>

const char *fileName = "soubor.txt";
const char *absenceFileName = "absence.txt";

typedef struct{
    int id; char jmeno[255]; char prijmeni[255];
} DATA;

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void moveCursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void pridatOsobu(){

    DATA osoba[1]; //-------------<----<<<<
    system("cls");

    //jmeno
    setTextColor(2);
    printf("vlozte jmeno: ");
    setTextColor(14);
    
    scanf("%s", &osoba[0].jmeno);

    //prijmeni
    setTextColor(2);
    printf("vlozte prijmeni: ");
    setTextColor(14);
    
    scanf("%s", &osoba[0].prijmeni);

    //id
    FILE *Rsoubor = fopen(fileName, "r");
    char buffer[1024];
    
    int index = 0, counter = 0;
    fgets(buffer, sizeof(buffer), Rsoubor);
        
    while(1){
        if(buffer[index] == '\0') break;
        else if(buffer[index] == '+') counter++;
        index++;
    }
    fclose(Rsoubor);

    //zapsat
    char toWrite[255];
    snprintf(toWrite, sizeof(toWrite), "+%d#%s#%s", counter, osoba[0].jmeno, osoba[0].prijmeni);

    FILE *Asoubor = fopen(fileName, "a");
    fprintf(Asoubor, toWrite);

    fclose(Asoubor);
}
int checkDate(char date[10]){
    if(date[3] == 0){
        if(date[4] != 0) return 1;
    }else if(date[3] == 1){
        if(date[4] <= 2) return 1;
    }
    return 0;
}
void pridatApsenci(){

    char obsah[255];
    FILE *studenti = fopen(fileName, "r");
    fgets(obsah, sizeof(obsah), studenti);
    int count = 0, idx = 0;
    while(obsah[idx+1] != '\n') if(obsah[idx] == '+') count++;

    int idStudenta;
    char datum[32]; char odDo[32];
    
    while(idStudenta<count){
        //id
        setTextColor(2);
        printf("vlozte id studenta: ");
        setTextColor(14);
        
        scanf("%d", &idStudenta);
    }
    while(1){
        //den
        setTextColor(2);
        printf("vlozte datum: ");
        setTextColor(14);
        
        scanf("%s", &datum);
        if(datum[0] == 0){
            if(datum[1] != 0 && checkDate(datum)) break;
        }else if(datum[0]<=3){
            if(datum[1]<=31 && checkDate(datum)) break;
        }
    }
    while(odDo[0]>=0 || odDo[0] > odDo[1]){
        //hodiny
        setTextColor(2);
        printf("vlozte od ktere do ktere hodiny [pr: 1-4]: ");
        setTextColor(14);
        
        scanf("%s", &odDo);
    }
    //zapsat
    char zapsat[255];
    snprintf(zapsat, sizeof(zapsat), "+#%d#%s#%s#", idStudenta, datum, odDo);

    FILE *absence = fopen(absenceFileName, "a");
    fprintf(absence, zapsat);
    system("cls");
    printf("\n");
}
void appendCharFromIndex(char* dest, const char* src, int srcIndex) {
    // printf("%s /-/ %d", src, srcIndex);
    // Check error
    if (srcIndex < 0 || srcIndex >= strlen(src)) {
        printf("ups!\n");
        return;
    }
    
    char temp[2] = {src[srcIndex], '\0'};
    
    strcat(dest, temp);
}
void vypis(){

    setTextColor(2);
    moveCursor(3,3); printf("id");
    moveCursor(19,3); printf("jmeno");
    moveCursor(35,3); printf("prijmeni");
    moveCursor(0,0);

    FILE *Rsoubor = fopen(fileName, "r");
    char buffer[1024];
    
    int index = 1, counter = 0, AddedAbsenceHeight = 0;
    fgets(buffer, sizeof(buffer), Rsoubor);


    FILE *Rabsence = fopen(absenceFileName, "r");
    char obsah[1024];

    fgets(obsah, sizeof(obsah), Rabsence);


    printf("*%s*\n*%s*", buffer, obsah);
    while(1){
        if(buffer[index] == '\0') break;

        for(int i = 0; i<3; i++){
            char destination[64] = "";
        
            while(buffer[index+1] != '#'){
                index++;
                appendCharFromIndex(destination, buffer, index);
            }
            if(i == 0){
                int printThis = 0;
                int index2 = 1;
                while(obsah[index2+1] != '\0'){
                    index2++;
                    for(int j = 0; j<10; j++){
                        if(j == 0 && obsah[index2] == buffer[index]){
                            printThis = 1;
                        }else if(printThis){
                            setTextColor(8);
                            moveCursor(10+i*16, 6+(AddedAbsenceHeight+counter)*3);
                            AddedAbsenceHeight++;
                        }
                    }
                    printThis = 0;
                }
            }
            /*
            if(i==0){
                int index2 = 1;
                while(1){
                    if(obsah[index2] == '\0') break;
                    
                    int printThis = 0;
                    for(int j = 0; j<3; j++){
                        char abs[255] = "";

                        while(obsah[index2+1] != '#' || obsah[index2+1] != '\0'){
                            index2++;
                            appendCharFromIndex(abs, obsah, index2);
                        }
                        setTextColor(3);
                        if(j == 0){
                            if(strcmp(abs, destination) == 0){
                                printThis = 1;
                            }
                        }
                        index2++;
                    
                        if(printThis){
                            moveCursor(10+j*16, 3+(AddedAbsenceHeight+counter)*3);
                            setTextColor(8);
                            printf("%s", abs);
                            AddedAbsenceHeight++;
                        }
                    }
                    index2++;
                }
            }
            */

            index++;

            moveCursor(3+i*16, 6+(AddedAbsenceHeight+counter)*3);
            setTextColor(4);
            printf("%s", destination);
            
        }
        index+=2;
        counter++;
    }
    fclose(Rsoubor); fclose(Rabsence);
}

int main(){
    char cwd[MAX_PATH];
    _getcwd(cwd, sizeof(cwd));

    _chdir(cwd);
    // printf("\n\n%s\n\n", cwd);

    
    // for(int i = 0; i<5; i++) pridatOsobu();
    // for(int i = 0; i<5; i++) pridatApsenci();

    vypis();

    return 0;
}