#include <MUIU8g2.h>
#include <U8g2lib.h>
#include <U8x8lib.h>

#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

int rAuto = 8;
int yAuto = 9;
int gAuto = 10;

int rChod = 11;
int gChod = 12;

int prechod = 2;
int nocPin = 3;

bool noc = false;
bool status = false;
bool chodGreen = false;

void setup(){

  pinMode(prechod, INPUT);
  pinMode(nocPin, INPUT);

  pinMode(rAuto, OUTPUT);
  pinMode(yAuto, OUTPUT);
  pinMode(gAuto, OUTPUT);

  pinMode(rChod, OUTPUT);
  pinMode(gChod, OUTPUT);

  // digitalWrite(yAuto, HIGH);
  // digitalWrite(gAuto, HIGH);

  // digitalWrite(rChod, HIGH);
  // digitalWrite(gChod, HIGH);
  
  interrupts();
  attachInterrupt(2, preruseni, FALLING);

  zacatek();
}
void loop(){

  if(noc){

    digitalWrite(rAuto, LOW);
    digitalWrite(gAuto, LOW);
    digitalWrite(yAuto, LOW);

    digitalWrite(rChod, LOW);
    digitalWrite(gChod, LOW);

    delay(200);

    digitalWrite(yAuto, HIGH);

    delay(200);

  }else if((digitalRead(prechod) == HIGH || status) && chodGreen == false){

    pustitChodce();
    delay(5000);
    pustitAuta();

    status = !status;
  }

  if(digitalRead(nocPin) == HIGH){
    if(noc) noc = false;
    else noc = true;
  }
}
void preruseni(){
  status = !status;
}
void zacatek(){

  digitalWrite(rChod, HIGH);

  digitalWrite(rAuto, HIGH);
  delay(1000);
  digitalWrite(yAuto, HIGH);
  delay(1000);
  digitalWrite(rAuto, LOW);
  digitalWrite(yAuto, LOW);
  
  digitalWrite(gAuto, HIGH);
  delay(500);
}
void pustitChodce(){

  digitalWrite(gAuto, LOW);
  digitalWrite(yAuto, HIGH);
  delay(1000);
  digitalWrite(rAuto, HIGH);
  digitalWrite(yAuto, LOW);
  delay(1000);
  digitalWrite(rChod, LOW);
  digitalWrite(gChod, HIGH);
  chodGreen = true;
}
void pustitAuta(){

  digitalWrite(gChod, LOW);
  chodGreen = true;
  zacatek();
}

