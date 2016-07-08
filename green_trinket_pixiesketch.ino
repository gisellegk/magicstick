/*
  Pixie reads data in at 115.2k serial, 8N1.
  Byte order is R1, G1, B1, R2, G2, B2, ... where the first triplet is the
  color of the LED that's closest to the controller. 1ms of silence triggers
  latch. 2 seconds silence (or overheating) triggers LED off (for safety).

  Do not look into Pixie with remaining eye!
*/

#include "SoftwareSerial.h"
#include "Adafruit_Pixie.h"

#define NUMPIXELS 1 // Number of Pixies in the strip
#define PIXIEPIN  0 // Pin number for SoftwareSerial output

SoftwareSerial pixieSerial(-1, PIXIEPIN);

Adafruit_Pixie strip = Adafruit_Pixie(NUMPIXELS, &pixieSerial);
// Alternately, can use a hardware serial port for output, e.g.:
// Adafruit_Pixie strip = Adafruit_Pixie(NUMPIXELS, &Serial1);

void setup() {
  int i;
  pixieSerial.begin(115200); // Pixie REQUIRES this baud rate
  strip.setBrightness(200);  // Adjust as necessary to avoid blinding
  
  strip.setPixelColor(0, 255, 0, 0);
  strip.show();
  delay(300);

  strip.setPixelColor(0, 0, 255, 0);
  strip.show();
  delay(300);

  strip.setPixelColor(0, 0, 0, 255);
  strip.show();
  delay(300);
}


void loop() {
  greenPulse();
}

void greenPulse() {
  for (int q = 100; q < 255; q++)
  {
    strip.setPixelColor(0, 0,q,0);
    strip.show();
    delay(10);
  }

  for (int r = 255; r > 100; r--)
  {
     strip.setPixelColor(0,0,r,0);
    strip.show();
    delay(10);
    }
}


