#include <U8g2lib.h>

const uint8_t SDA_PIN = A5;
const uint8_t SCK_PIN = A4;

// order: rotation, clock, data, reset
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, SCK_PIN, SDA_PIN, U8X8_PIN_NONE);

unsigned long counter = 0;

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0, 14, "Hello Nano!");   // x, y (y = text baseline)

    u8g2.drawHLine(0, 20, 128);

    u8g2.setCursor(0, 45);
    u8g2.print("Count: ");
    u8g2.print(counter);
  } while (u8g2.nextPage());

  counter++;
  delay(500);
}