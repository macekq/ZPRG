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
void moveCursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
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
char* subString(const char* str, int start, int length) {
    char* sub = malloc(length + 1);
    strncpy(sub, str + start, length);  // Use pointer arithmetic
    sub[length] = '\0';
    return sub;
}
void vypis(){

    system("cls");

    // char obsahStudenti[255];char obsahAbsence[255];

    FILE *studenti = fopen(fileName, "r");
    FILE *absence  = fopen(absenceFileName, "r");
    
    char stud[1024];
    
    fgets(stud, sizeof(stud), studenti);
    // for(int j = 0; j<3; j++){
        
    //     fgets(stud, sizeof(stud), studenti);
    //     printf("%s\n", stud);
    // }
    int counter = 0;
    while(1){
        counter++;
        moveCursor(10,50+counter+2);


        fgets(stud, sizeof(stud), studenti);

        printf("%s", stud);  

        int startIndex = 0, endIndex = 0;
        for(int i = 0; i<3; i++){
            //jmeno:
            while(stud[endIndex] != '#') endIndex++;
            char *text = (char*)malloc(sizeof(stud));
            text = subString(stud, startIndex, endIndex - startIndex);

            moveCursor(4+16*i, 4);
            printf("%s", text);
        
            startIndex = endIndex;
        }
        if(stud[strlen(stud)-2] != '+') break;
    }


}

int main(){
    _chdir(path);

    // pridatApsenci();
    // pridatOsobu();

    vypis();

    return 0;
}