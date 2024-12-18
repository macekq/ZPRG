#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

float **HORSES;
int horsesLength = 0;

void addHorse(){

    float speed = rand()%50;
    speed /= 100, speed += 1;

    HORSES[horsesLength] = {0, speed};
}

int main(){
    srand(time(NULL));

    for(int i = 0; i<10; i++) addHorse();

    return 0;
}

