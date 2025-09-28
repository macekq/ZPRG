#include <stdio.h>
#include <string.h>

void appendCharFromIndex(char* dest, const char* src, int srcIndex) {
    // Check error
    if (srcIndex < 0 || srcIndex >= strlen(src)) {
        printf("ups!\n");
        return;
    }
    
    char temp[2] = {src[srcIndex], '\0'};
    
    strcat(dest, temp);
}

int main() {
    char source[255] = "+#0#karel#barel#+#1#dratenka#kutilAOpravar#+#2#radim#doradil#+#3#david#schizofrenik#+#4#kedluben#odHoven#";
    char source2[255] = "+#0#karel#barel#+#1#dratenka#kutilAOpravar#+#2#radim#doradil#+#3#david#schizofrenik#+#4#kedluben#odHoven#";
    int index = 1;
    int index2 = 1;
    
    for(int i = 0; i<3; i++){
        char destination[64] = "";
        
        while(source[index+1] != '#'){
            index++;
            appendCharFromIndex(destination, source, index);
        }
        if(i == 0){
            printf("%d", strcpm(source2, source));
        }
        index++;
        printf("%s\n", destination);    
    }

    return 0;
}