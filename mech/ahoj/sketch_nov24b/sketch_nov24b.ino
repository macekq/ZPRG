#include <Arduino.h>
#include <U8g2lib.h>
#include <DHT.h>

#define DHTPIN  A0         // datovy pin DHT11 (analogovy pin pouzity jako digitalni)
#define DHTTYPE DHT11

U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
DHT dht(DHTPIN, DHTTYPE);

float teplota = NAN;
float vlhkost = NAN;
unsigned long posledniCteni = 0;
const unsigned long INTERVAL_CTENI = 2000;   // DHT11 zvladne max. 1 cteni za ~1 s

void setup(void) {
  Serial.begin(9600);
  dht.begin();
  u8g2.begin();
}

void loop(void) {
  // cteni senzoru jen kazde 2 s
  if (posledniCteni == 0 || millis() - posledniCteni >= INTERVAL_CTENI) {
    posledniCteni = millis();
    vlhkost = dht.readHumidity();
    teplota = dht.readTemperature();

    if (isnan(teplota) || isnan(vlhkost)) {
      Serial.println("Chyba cteni DHT11");
    } else {
      Serial.print("Teplota: ");
      Serial.print(teplota, 1);
      Serial.print(" C, Vlhkost: ");
      Serial.print(vlhkost, 1);
      Serial.println(" %");
    }
  }

  char tBuf[8];
  char hBuf[8];
  char radek[24];

  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_6x12_tf);    // nastaveni fontu
    u8g2.drawStr(0, 11, "DHT11 + OLED U8g2");
    u8g2.drawStr(0, 23, "***************");

    if (isnan(teplota) || isnan(vlhkost)) {
      u8g2.drawStr(0, 41, "Chyba cteni DHT11");
    } else {
      dtostrf(teplota, 4, 1, tBuf);
      dtostrf(vlhkost, 4, 1, hBuf);

      snprintf(radek, sizeof(radek), "Teplota: %s \xb0" "C", tBuf);
      u8g2.drawStr(0, 41, radek);

      snprintf(radek, sizeof(radek), "Vlhkost: %s %%", hBuf);
      u8g2.drawStr(0, 55, radek);
    }
  } while ( u8g2.nextPage() );
}