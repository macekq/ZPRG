#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <direct.h>

//absolutni cesta z slozce s knihovna.dat protoze mi nefungovala relativni
// char *path = "C:\\Users\\l.macura.st\\Documents\\GitHub\\ZPRG\\c\\2026_2027\\spravaKnih-01-10-26\\data";
char *path = "C:\\Users\\lukma\\OneDrive\\Documents\\GitHub\\ZPRG\\c\\2026_2027\\spravaKnih-01-10-26\\data";

void moveCursor(int col, int row) {
    printf("\033[%d;%dH", row, col);
}
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

//pravdepodobne zbytecna funkce ale nebudu to prepisovat bo to funguje
KNIHA tempSaveKniha(KNIHA kniha, char *ISBN, char *nazev, int rokVydani, int cena) {

    strncpy(kniha.ISBN, ISBN, sizeof(kniha.ISBN) - 1);
    kniha.ISBN[sizeof(kniha.ISBN) - 1] = '\0';

    strncpy(kniha.nazev, nazev, sizeof(kniha.nazev) - 1);
    kniha.nazev[sizeof(kniha.nazev) - 1] = '\0';

    kniha.rokVydani = rokVydani;
    kniha.cena = cena;

    return kniha;
}

//uklada zaznam z [getUserInput] do dlouhodobe pameti (knihovna.dat)
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

//po jednom nacita hodnoty z klavesnice od uzivatele a vola funkci [saveKniha] 
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

    }

    free(knihy);
    knihy = NULL;
}

//slouzi jen k vytisknuti dat ze souboru knihovna.dat
void readData(){
    char cesta[255];
    snprintf(cesta, sizeof(cesta), "%s\\%s", path, "knihovna.dat");

    FILE *file = fopen(cesta, "rb");
    KNIHA k;

    setTextColor(11);
    printf("\nVYPIS KNIH:\n================\n");
    setTextColor(7);
    
    while(fread(&k, sizeof k, 1, file)){
        printf("%s - %s - %d - %d\n", k.ISBN, k.nazev, k.rokVydani, k.cena);
    }
    fclose(file);
}

//vrati pocet ulozenych zazanamu o knihach
int getBookCount(){

    char cesta[255];
    snprintf(cesta, sizeof(cesta), "%s\\%s", path, "knihovna.dat");

    FILE *file = fopen(cesta, "rb");
    KNIHA k;

    int len = 0;
    while(fread(&k, sizeof k, 1, file)){
        len++;
    }
    return len;
}

int containsWord(char *haystack, char *needle){
    return strstr(haystack, needle) != NULL;
} 
void printBook(KNIHA k, int y){

    moveCursor(0, y+3);
    printf("%s", k.ISBN);
    moveCursor(32, y+3);
    printf("%s", k.nazev);
    moveCursor(64, y+3);
    printf("%d", k.rokVydani);
    moveCursor(96, y+3);
    printf("%d", k.cena);
}

void bubbleSortBooks(KNIHA knihy[], int len) {

    for(int i = 0; i < len - 1; i++) {

        for(int j = 0; j < len - i - 1; j++) {

            if(knihy[j].cena < knihy[j + 1].cena) {

                KNIHA temp = knihy[j];
                knihy[j] = knihy[j + 1];
                knihy[j + 1] = temp;
            }
        }
    }

    setTextColor(11);
    printf("KNIHY SERAZENE PODLE CENY:\n====================================\n");
    setTextColor(7);
    for(int item = 0; item<len; item++){
        printBook(knihy[item], item);
    }
}

void searchData(){

    int len = getBookCount();
    KNIHA *knihy = (KNIHA *)malloc(len*sizeof(KNIHA));
    
    char cesta[255];
    snprintf(cesta, sizeof(cesta), "%s\\%s", path, "knihovna.dat");
    
    FILE *file = fopen(cesta, "rb");
    KNIHA k;
    
    double sum = 0;
    int min = 0, max = 0;
    
    //nacitani hodnot z (knihovna.dat)
    for(int i = 0; i<len; i++){
        
        fread(&k, sizeof k, 1, file);
        
        strcpy(knihy[i].ISBN, k.ISBN);
        strcpy(knihy[i].nazev, k.nazev);
        knihy[i].rokVydani = k.rokVydani;
        knihy[i].cena = k.cena;
        
        sum += k.cena;
        if(i == 0){
            min = k.cena;
            max = k.cena;
        }else{
            if(k.cena < min)
                min = k.cena;

            if(k.cena > max)
                max = k.cena;
        }
    }
    
    char slovo[255];
    int pred = 0, po = 0;
    char input;
    while(input != 'q'){
        
        
        //tisknuti nove nactenych hodnot
        system("cls");

        moveCursor(0, 50);
        printf("nums: %d - %d - %s", pred, po, slovo);
        
        setTextColor(4);
        char atributy[4][12] = {"ISBN", "NAZEV", "ROK VYDANI", "CENA"};
        for(int post = 0; post<4; post++){
            moveCursor(post*32, 0);
            printf("%s", atributy[post]);
        }
        
        setTextColor(7);
        for(int j = 0; j<len; j++){
            
            if(po != 0){

                if(knihy[j].rokVydani >= po) setTextColor(14);
                else setTextColor(8);

                printBook(knihy[j], j);
                
            }else if(pred != 0){
                
                if(knihy[j].rokVydani <= pred) setTextColor(14);
                else setTextColor(8);
                
                printBook(knihy[j], j);
                
            }else if(slovo[0] != '\0'){

                if(containsWord(knihy[j].nazev, slovo)) setTextColor(14);
                else setTextColor(8);    
                
                printBook(knihy[j], j);

            }else{ 
                printBook(knihy[j], j);
            
            }

        }
        
        setTextColor(8);
        printf("\nnejlevnejsi: %d", min);
        printf("\nnejdrazsi: %d", max);
        printf("\nprumerna cena: %.2f", sum/len);

        setTextColor(11);
        printf("\n\nFILTROVAT:\n================\n");
        setTextColor(7);
        printf("[T] podle klicoveho slova\n[A] vydano po roce 'x'\n[B] vydano pred rokem 'x'\n[Q] pro ukonceni pohledu");
        
        input = getch();

        if(input == 'a'){
            printf("\n\nvydano po roce: ");
            scanf("%d", &po);
        }else po = 0;
        
        if(input == 'b'){
            printf("\n\nvydano pred rokem: ");
            scanf("%d", &pred);
        }else pred = 0;

        if(input == 't'){
            printf("\n\nklicove slovo: ");
            scanf("%s", slovo);
        }else slovo[0] = '\0';

    }
    system("cls");
    bubbleSortBooks(knihy, len);
    getch();

    free(knihy);
    knihy = NULL;
}

int main (){

    _mkdir(path);
    _chdir(path);

    char cesta[255];
    snprintf(cesta, sizeof(cesta), "%s\\%s", path, "knihovna.dat");

    FILE *file = fopen(cesta, "rb");
    if(file == NULL){
        
        fclose(file);
        FILE *soubor = fopen(cesta, "wb");
        fclose(soubor);

    }else fclose(file);

    char input;
    while(input != 'q'){
        system("cls");

        setTextColor(11);
        printf("\nMOZNOSTI:\n================\n");
        setTextColor(7);
        printf("[+] pro pridani knih\n[R] pro vypis knih\n[A] pro praci s daty\n[Q] pro ukonceni\n\n");

        input = getch();

        if(input == '+'){
            int pocet;

            system("cls");

            printf("pocet knih pro pridani: ");
            scanf("%d", &pocet);

            printf("\nnum -> %d", pocet);
            getUserInput(pocet);

        }else if(input == 'a'){

            // system("cls");
            searchData();

        }else if(input == 'r'){
            
            system("cls");
            readData();

            setTextColor(8);
            printf("\n\nstisknete jakoukoliv klavesu pro ukonceni pohledu");
            getch();
        } 
    }

    return 0;
}