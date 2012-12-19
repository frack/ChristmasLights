#include "LPD8806.h"
#include "SPI.h"
int nLEDs = 260;
int dataPin  = 13;
int clockPin = 11;
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

void setup() {
  randomSeed(analogRead(0));    // Pin not connected, so randomly floating
  strip.begin();
  for(int i=0; i<nLEDs; i++)    // First fill strip with random low values
    strip.setPixelColor(i,1,1,1);
}

void loop() {
  uint16_t i = random(0,nLEDs);    // Choose random led
  for(int x=127; x>10; x=x-8) {
    strip.setPixelColor(i,x,x,x);
    strip.show();
  }
  strip.setPixelColor(i,1,1,1);
  strip.show();
}

