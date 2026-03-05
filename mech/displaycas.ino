#include <Wire.h>
#include <RTClib.h>
     
 RTC_DS1307 rtc; 
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, A2, A1, U8X8_PIN_NONE);

int start = 8; int reset = 9; int interval = 10;
long time;

void setup() {
  u8g2.begin();

  pinMode(start, INPUT_PULLUP);
  pinMode(reset, INPUT_PULLUP);
  pinMode(interval, INPUT_PULLUP);


  while (!Serial);          // for Leonardo/Micro/Zero
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }                         // end rtc.begin()
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");  
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }    

  time = millis();
}
  
int startTime = 0;
int stopky = 0;
char cas[64];


void loop() {    

  DateTime now = rtc.now();
  char timeFormat[] = "YYYY.DD.MM-hh:mm:ss";
  
  if(digitalRead(start) == 0 && stopky == 0){
    stopky = 1;
  }
  else if(digitalRead(start) == 0 && stopky == 1){
    stopky = 0;
    startTime = 0;
  }
  if(stopky == 1){
    if(millis() - time >= 1000){
      time = millis();
      startTime++;
      snprintf(cas,64, "%d s", startTime);
    }
  }
  Serial.println(digitalRead(start));

  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB08_tr);
    
    u8g2.drawStr(0, 12, now.toString(timeFormat)); 
    u8g2.drawStr(0, 28, cas);
    u8g2.drawStr(0, 44, "I can see this too");

  } while ( u8g2.nextPage() );

}