#include <stdio.h>

int main(){

    char myStr[] = "Learn C++ at W3schools";
    char * myPtr = strtok(myStr, " ");
    while(myPtr != NULL) {
        cout << myPtr << "\n";
        myPtr = strtok(NULL, " ");
    }
    return 0;
}

/*
Definition and Usage

The strtok() function splits a string into multiple pieces (referred to as "tokens") using delimiters.

The first call to strtok() should have a pointer to the string which should be split, while any following calls should use NULL as an argument.
Each time the function is called a pointer to a different token is returned until there are no more tokens. At that point each function call returns NULL.

Be aware that this function modifies the original string, replacing delimiters with null terminating characters
so that each token can have its own null terminating character.

The strtok() function is defined in the <string.h> header file.



Syntax

strtok(char * str, const char * delimiters);

Parameter Values

Parameter 	Description
str 	   -    Required. A pointer to the string to begin splitting. After the first call, pass NULL to this parameter to get more pieces from the same string.
delimiters -	Required. A set of delimiters to search for. A token ends when any one of these characters is found.

Technical Details
Returns: 	A char type pointer to the position of one of the tokens in the original string, or NULL if there are no more tokens.
*/