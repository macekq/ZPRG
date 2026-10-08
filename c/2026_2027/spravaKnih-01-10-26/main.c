#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <direct.h>

char *path = "C:\\Users\\l.macura.st\\Documents\\GitHub\\ZPRG\\c\\2026_2027\\spravaKnih-01-10-26\\data";

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

typedef struct{
    char ISBN[16];
    char nazev[256];
    int rokVydani;
    int cena;
} KNIHA;

KNIHA tempSaveKniha(KNIHA kniha, char *ISBN, char *nazev, int rokVydani, int cena) {

    strncpy(kniha.ISBN, ISBN, sizeof(kniha.ISBN) - 1);
    kniha.ISBN[sizeof(kniha.ISBN) - 1] = '\0';

    strncpy(kniha.nazev, nazev, sizeof(kniha.nazev) - 1);
    kniha.nazev[sizeof(kniha.nazev) - 1] = '\0';

    kniha.rokVydani = rokVydani;
    kniha.cena = cena;

    return kniha;
}
void saveKniha(KNIHA kniha){

    char cesta[255];
    snprintf(cesta, sizeof(cesta), "%s\\%s", path, "knihovna.dat");

    _chdir(path);
    FILE *soubor = fopen("knihovna.dat", "ab");
    // char content[512];
    // snprintf(content, sizeof(content), "%s■%s■%d■%d;\n", kniha.ISBN, kniha.nazev, kniha.rokVydani, kniha.cena);
    fwrite(&kniha, sizeof kniha, 1, soubor);
    fclose(soubor);

}
void getUserInput(int pocet){


    KNIHA *knihy = (KNIHA *)malloc(pocet*sizeof(KNIHA));

    if(knihy == NULL){
        printf("tudy cesta nevede");
        return;
    }

    char ISBN[16], nazev[255];
    int cena, rokVydani;
    for(int i = 0; i<pocet; i++){

        printf("\nzadejte ISBN knihy: ");
        scanf("%s", ISBN);

        printf("\nzadejte nazev knihy: ");
        scanf("%s", nazev);

        printf("\nzadejte rok vydani knihy: ");
        scanf("%d", &rokVydani);

        printf("\nzadej cenu knihy: ");
        scanf("%d", &cena);


        knihy[i] = tempSaveKniha(knihy[i], ISBN, nazev, rokVydani, cena);

        system("cls");

        // printf("%s, %s, %d, %d", ISBN, nazev, rokVydani, cena);
    }


    setTextColor(11);
    printf("ulozit data? [Y/n]\n============\n");
    setTextColor(7);

    for(int j = 0; j<pocet; j++){

        printf("ISBN: %s", knihy[j].ISBN);
        printf("\nnazev: %s", knihy[j].nazev);
        printf("\nrok vydani: %d", knihy[j].rokVydani);
        printf("\ncena: %d", knihy[j].cena);
        printf("\n======================\n");
    }

    if(getch() == 'y'){

        system("cls");
        printf("ulozeno\n\n");
        for(int item = 0; item<pocet; item++) saveKniha(knihy[item]);

    }else return;

}

void readData(){
    _chdir(path);
    char cesta[255];
    snprintf(cesta, sizeof(cesta), "%s\\%s", path, "knihovna.dat");

    FILE *file = fopen(cesta, "rb");
    KNIHA k;

    setTextColor(11);
    printf("\nVYPIS KNIH:\n================\n");
    setTextColor(7);
    for(int i = 0; i<10; i++){
        size_t count = fread(&k, sizeof k, 1, file);
        if(count) printf("%s - %s - %d - %d\n", k.ISBN, k.nazev, k.rokVydani, k.cena);
    }
}

int main (){

    _mkdir(path);
    _chdir(path);
/*
    char cesta[255];
    snprintf(cesta, sizeof(cesta), "%s\\%s", path, "knihovna.dat");

    FILE *file = fopen(cesta, "wb");
    fclose(file);
*/
    char input;
    while(input != 'q'){


        setTextColor(11);
        printf("\nMOZNOSTI:\n================\n");
        setTextColor(7);
        printf("[+] pro pridani knih\n[R] pro vypis knih\n[Q] pro ukonceni\n\n");

        input = getch();

        if(input == '+'){
            int pocet;

            system("cls");

            printf("pocet knih pro pridani: ");
            scanf("%d", &pocet);

            printf("\nnum -> %d", pocet);
            getUserInput(pocet);

        }else if(input == 'r'){

            readData();
        }
    }

    return 0;
}
