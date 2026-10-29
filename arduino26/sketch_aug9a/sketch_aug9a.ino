#include <LiquidCrystal.h>

const int trigPin = 9;
const int echoPin = 10;

const int bzucak = A0;
const int led = A5;

float duration, distance;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  lcd.print("vzdalenost je:");
}

float timer = 0;
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  if(millis() > timer + 250){

    timer = millis();

    distance = (duration*0.0343)/2;
    float metry = distance/100;

    if(metry < 0.2){
      analogWrite(bzucak, 255);
      analogWrite(led, 255);
    }
    else if(metry < 0.65){
      int vzdalenost = distance;
      int val = map(vzdalenost, 65, 20, 0, 255);
      Serial.print("val -> ");
      Serial.println(val);
      
      analogWrite(led, val);
      analogWrite(bzucak, val);
    }
    else{
      analogWrite(led, 0);
      analogWrite(bzucak, 0);
    } 
  
    Serial.println(metry);

    lcd.setCursor(5, 1);
    lcd.print(metry);
    lcd.print("m");
    
  }            
}