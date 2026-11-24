#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <DHT.h>

#define DHTPIN  A0         // datovy pin DHT11 (analogovy pin pouzity jako digitalni)
#define DHTTYPE DHT11

// hardwarove I2C (SDA = A4, SCL = A5 na Uno/Nano) - mnohem rychlejsi nez SW_I2C
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
DHT dht(DHTPIN, DHTTYPE);

float teplota = NAN;
float vlhkost = NAN;
unsigned long posledniCteni = 0;
const unsigned long INTERVAL_CTENI = 2000;   // DHT11 zvladne max. 1 cteni za ~1 s

// vykresli displej - vola se jen kdyz jsou nova data, ne v kazdem loop()
void vykresli() {
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

void setup(void) {
  Serial.begin(9600);
  dht.begin();
  u8g2.begin();
  u8g2.setBusClock(400000);   // rychle I2C (400 kHz)
  vykresli();
}

void loop(void) {
  // cteni senzoru jen kazde 2 s
  if (millis() - posledniCteni >= INTERVAL_CTENI) {
    posledniCteni = millis();

    float noveT = dht.readTemperature();
    float noveH = dht.readHumidity();

    if (isnan(noveT) || isnan(noveH)) {
      Serial.println("Chyba cteni DHT11");
    } else {
      Serial.print("Teplota: ");
      Serial.print(noveT, 1);
      Serial.print(" C, Vlhkost: ");
      Serial.print(noveH, 1);
      Serial.println(" %");
    }

    // prekreslit jen kdyz se hodnota zmenila (NAN != NAN, proto zvlast test)
    bool zmena = (noveT != teplota) || (noveH != vlhkost);
    if (isnan(noveT) && isnan(teplota) && isnan(noveH) && isnan(vlhkost)) zmena = false;

    teplota = noveT;
    vlhkost = noveH;

    if (zmena) vykresli();
  }
}