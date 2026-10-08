#include "SevSeg.h"
SevSeg sevseg;

void setup() {
    byte numDigits = 4;  
    byte digitPins[] = {12, 3, 4, 11};
    byte segmentPins[] = {13, 5, 9, 7, 6, 2, 10, 8};
    bool resistorsOnSegments = 0; 
  
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(60);
}

void loop() {
    sevseg.setChars("8080"); // set the characters/numbers to display.
    sevseg.refreshDisplay();
}