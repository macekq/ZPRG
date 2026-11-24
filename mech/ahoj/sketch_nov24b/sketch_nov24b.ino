#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <DHT.h>

#define DHTPIN  A0         // datovy pin DHT11 (analogovy pin pouzity jako digitalni)
#define DHTTYPE DHT11

// hardwarove I2C (SDA = A4, SCL = A5 na Uno/Nano) - mnohem rychlejsi nez SW_I2C
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
DHT dht(DHTPIN, DHTTYPE);

// ================== 4mistny 7segmentovy displej ==================
// Pokud cislice nesedi s zapojenim, staci prehodit cisla pinu v polich.
const byte PINY_CISLIC[4]   = {2, 3, 4, 5};                    // D1 (vlevo) .. D4 (vpravo)
const byte PINY_SEGMENTU[8] = {6, 7, 8, 9, 10, 11, 12, 13};    // a, b, c, d, e, f, g, dp

// 5641AS = spolecna katoda -> true, 5641BS = spolecna anoda -> false
const bool SPOLECNA_KATODA = true;

// co se ma zobrazit na kazde cislici (bity: 0=a ... 6=g, 7=dp)
byte displej[4] = {0, 0, 0, 0};
byte aktivniCislice = 0;
unsigned long posledniMultiplex = 0;
const unsigned long MULTIPLEX_US = 2000;   // kazda cislice sviti 2 ms

// prevod znaku na segmenty (bit 0 = a, 1 = b, ... 6 = g)
byte znakNaSegmenty(char z) {
  switch (z) {
    case '0': return 0b0111111;
    case '1': return 0b0000110;
    case '2': return 0b1011011;
    case '3': return 0b1001111;
    case '4': return 0b1100110;
    case '5': return 0b1101101;
    case '6': return 0b1111101;
    case '7': return 0b0000111;
    case '8': return 0b1111111;
    case '9': return 0b1101111;
    case 'A': return 0b1110111;
    case 'b': return 0b1111100;
    case 'C': return 0b0111001;
    case 'd': return 0b1011110;
    case 'E': return 0b1111001;
    case 'F': return 0b1110001;
    case 'H': return 0b1110110;
    case 'L': return 0b0111000;
    case 'P': return 0b1110011;
    case 'r': return 0b1010000;
    case 'o': return 0b1011100;
    case '-': return 0b1000000;
    case '_': return 0b0001000;
    default:  return 0;          // mezera / neznamy znak = zhasnuto
  }
}

// ---- adresovani jednotlivych cislic ----
// pozice 0..3 (0 = vlevo), znak napr. '7', 'C', '-', ' ', tecka = rozsviti desetinnou tecku
void nastavCislici(byte pozice, char znak, bool tecka = false) {
  if (pozice > 3) return;
  displej[pozice] = znakNaSegmenty(znak) | (tecka ? 0b10000000 : 0);
}

// primo nastavit segmenty (bit 0 = a ... 6 = g, 7 = dp)
void nastavSegmenty(byte pozice, byte segmenty) {
  if (pozice > 3) return;
  displej[pozice] = segmenty;
}

void zhasniCislici(byte pozice) {
  nastavSegmenty(pozice, 0);
}

void vymazDisplej() {
  for (byte i = 0; i < 4; i++) displej[i] = 0;
}

// vola se co nejcasteji z loop() - rozsviti vzdy jednu cislici po druhe
void obnovDisplej() {
  if (micros() - posledniMultiplex < MULTIPLEX_US) return;
  posledniMultiplex = micros();

  // zhasnout aktualni cislici
  digitalWrite(PINY_CISLIC[aktivniCislice], SPOLECNA_KATODA ? HIGH : LOW);

  // dalsi cislice
  aktivniCislice = (aktivniCislice + 1) % 4;

  // nastavit segmenty
  for (byte s = 0; s < 8; s++) {
    bool sviti = displej[aktivniCislice] & (1 << s);
    digitalWrite(PINY_SEGMENTU[s], (sviti == SPOLECNA_KATODA) ? HIGH : LOW);
  }

  // rozsvitit cislici
  digitalWrite(PINY_CISLIC[aktivniCislice], SPOLECNA_KATODA ? LOW : HIGH);
}

// ================== DHT11 + OLED ==================
float teplota = NAN;
float vlhkost = NAN;
unsigned long posledniCteni = 0;
const unsigned long INTERVAL_CTENI = 2000;   // DHT11 zvladne max. 1 cteni za ~1 s

// vykresli OLED - vola se jen kdyz jsou nova data, ne v kazdem loop()
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

// teplotu na 7segment, napr. "23.5C"; pri chybe "Err "
void teplotaNa7seg() {
  if (isnan(teplota)) {
    nastavCislici(0, 'E');
    nastavCislici(1, 'r');
    nastavCislici(2, 'r');
    nastavCislici(3, ' ');
    return;
  }
  int t = (int)(teplota * 10 + (teplota >= 0 ? 0.5 : -0.5));   // 23.5 -> 235
  bool zaporna = t < 0;
  if (zaporna) t = -t;
  if (t > 999) t = 999;

  int desitky = t / 100;
  nastavCislici(0, zaporna ? '-' : (desitky ? '0' + desitky : ' '));
  nastavCislici(1, '0' + (t / 10) % 10, true);   // s desetinnou teckou
  nastavCislici(2, '0' + t % 10);
  nastavCislici(3, 'C');
}

void setup(void) {
  Serial.begin(9600);

  for (byte i = 0; i < 4; i++) {
    pinMode(PINY_CISLIC[i], OUTPUT);
    digitalWrite(PINY_CISLIC[i], SPOLECNA_KATODA ? HIGH : LOW);   // vse zhasnuto
  }
  for (byte i = 0; i < 8; i++) pinMode(PINY_SEGMENTU[i], OUTPUT);

  // test: kazda cislice zvlast
  nastavCislici(0, '1');
  nastavCislici(1, '2');
  nastavCislici(2, '3');
  nastavCislici(3, '4');

  dht.begin();
  u8g2.begin();
  u8g2.setBusClock(400000);   // rychle I2C (400 kHz)
  vykresli();
}

void loop(void) {
  obnovDisplej();

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

    teplotaNa7seg();
    if (zmena) vykresli();
  }
}