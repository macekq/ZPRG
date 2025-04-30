#include <stdio.h>
//nezbytny include
#include <dirent.h>

//ukazka kodu, zpracova vsechny nalezene soubory v zadane slozce
//(v nasem pripade vypisuje jejich nazvy)
int main(int argc, char *argv[]) {
  DIR *sl;
  struct dirent *slozka;

  sl = opendir("./data");
  if (sl) {
    while ((slozka = readdir(sl)) != NULL) {
      printf("%s", slozka->d_name);
    }
    closedir(sl);
  }
  return 0;
}