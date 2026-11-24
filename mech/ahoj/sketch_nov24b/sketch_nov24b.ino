// OLED test for GM009605 (0.96" 128x64 SSD1306, I2C) on Arduino Nano
//
// Wiring:
//   OLED GND -> Nano GND
//   OLED VCC -> Nano 5V
//   OLED SCL -> Nano A5
//   OLED SDA -> Nano A4
//
// Libraries (Arduino IDE: Tools > Manage Libraries):
//   "Adafruit SSD1306" (also installs "Adafruit GFX Library")

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C   // try 0x3D if the screen stays blank

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 not found - check wiring/address"));
    while (true) {}
  }
  Serial.println(F("Display OK"));

  // Splash screen
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(10, 10);
  display.println(F("Hello!"));
  display.setTextSize(1);
  display.setCursor(10, 40);
  display.println(F("Display works :)"));
  display.display();
  delay(2000);
}

void loop() {
  static unsigned int counter = 0;

  display.clearDisplay();

  // Title
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("GM009605 test"));
  display.drawLine(0, 10, 127, 10, SSD1306_WHITE);

  // Big counter
  display.setTextSize(2);
  display.setCursor(0, 16);
  display.print(F("Count:"));
  display.println(counter);

  // Uptime and a fake sensor value
  display.setTextSize(1);
  display.setCursor(0, 38);
  display.print(F("Uptime: "));
  display.print(millis() / 1000);
  display.println(F(" s"));
  display.print(F("A0: "));
  display.println(analogRead(A0));

  // Progress bar that fills and resets
  int barWidth = (counter % 21) * 6;
  display.drawRect(0, 56, 126, 8, SSD1306_WHITE);
  display.fillRect(0, 56, barWidth, 8, SSD1306_WHITE);

  display.display();

  counter++;
  delay(500);
}