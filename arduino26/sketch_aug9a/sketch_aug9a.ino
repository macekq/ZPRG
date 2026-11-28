#include <SevSeg.h>   // Library Manager: "SevSeg" by Dean Reading

SevSeg sevseg;

const uint8_t NUM_DIGITS = 4;
const uint8_t digitPins[NUM_DIGITS] = {13, 12, 11, 10};          // d1..d4, left to right
const uint8_t segmentPins[8]        = {2, 3, 4, 5, 6, 7, 8, 9};  // a, b, c, d, e, f, g, dp

char displayText[NUM_DIGITS + 1] = "    ";

// digit: 1..4 (left to right), number: 0..9
void showDigit(uint8_t digit, uint8_t number) {
  displayText[digit - 1] = '0' + number;
  sevseg.setChars(displayText);
}
void setup() {
  sevseg.begin(COMMON_CATHODE, NUM_DIGITS, digitPins, segmentPins, true);  // true = resistors on segments
  sevseg.setBrightness(90);

  showDigit(1, 1);
  showDigit(2, 2);
  showDigit(3, 3);
  showDigit(4, 4);
}

double timer = 0;
int numer = 1;
void loop() {
  sevseg.refreshDisplay();   // keep calling this, no delay() in loop

  if(millis() > timer+1000){

  }
}