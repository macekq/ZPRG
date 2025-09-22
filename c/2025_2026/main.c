#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <Windows.h>
// #include <conio.h>
#include <string.h>

const char *path = "C:\\Users\\l.macura.st\\Documents\\GitHub\\ZPRG\\c\\2025_2026";
const char *fileName = "soubor.txt";
const char *absenceFileName = "absence.txt";

typedef struct{
    int id; char jmeno[255]; char prijmeni[255];
} DATA;

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void pridatOsobu(){

    DATA osoba[5];
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
    
    int counter = 0;
     while(1){
        counter++;
        fgets(buffer, sizeof(buffer), Rsoubor);
        printf("%s\n%d\n%c", buffer, strlen(buffer)-1, buffer[0]);
        if(buffer[strlen(buffer)-2] != '+') break;
    }
    fclose(Rsoubor);

    //zapsat
    char toWrite[255];
    snprintf(toWrite, sizeof(toWrite), "+\n%d#%s#%s", counter, osoba[0].jmeno, osoba[0].prijmeni);

    FILE *Asoubor = fopen(fileName, "a");
    fprintf(Asoubor, toWrite);

    fclose(Asoubor);
}
void pridatApsenci(){

    int idStudenta;
    char datum[32]; char odDo[32];
    
    //id
    setTextColor(2);
    printf("vlozte id studenta: ");
    setTextColor(14);
    
    scanf("%d", &idStudenta);

    //den
    setTextColor(2);
    printf("vlozte datum: ");
    setTextColor(14);
    
    scanf("%s", &datum);

    //hodiny
    setTextColor(2);
    printf("vlozte do ktere do ktere hodiny [pr: 1-4]: ");
    setTextColor(14);
    
    scanf("%s", &odDo);

    //zapsat
    char zapsat[255];
    snprintf(zapsat, sizeof(zapsat), "+\n%d#%s#%s", idStudenta, datum, odDo);

    FILE *absence = fopen(absenceFileName, "a");
    fprintf(absence, zapsat);
}
void vypis(){

    char obsahStudenti[255];char obsahAbsence[255];

    FILE *studenti = fopen(fileName, "r");
    FILE *absence  = fopen(absenceFileName, "r");

    for(int i = 0; i<3; i++){
        fgets(obsahStudenti, sizeof(obsahStudenti), studenti);
        printf("%s\n", studenti);
    }
}

int main(){
    _chdir(path);

    // pridatApsenci();
    // pridatOsobu();

    vypis();

    return 0;
}