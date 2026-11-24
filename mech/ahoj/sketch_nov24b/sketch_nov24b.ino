#include <Arduino.h>
#include <U8g2lib.h>
 
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
 
void setup(void) {
  u8g2.begin();  
}
 
void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_6x12_tf);    // nastaveni fontu
    u8g2.drawStr(0,11,"Test pro OLED U8g2");  // vystup
    u8g2.drawStr(0,23,"***************");
    u8g2.drawStr(0,35,"Tento font je");
    u8g2.drawStr(0,47,"bez diakritiky");
    u8g2.drawStr(0,59,"===== !!! =====");
  } while ( u8g2.nextPage() );
}