#include "ambient.h"
#include <Arduino.h>

CRGB Ambient::rgbLed[1] = {CRGB::Black};

void Ambient::setup()
{
  Serial.println("Ambient setup");
  FastLED.addLeds<WS2812, AMBIENT_PIN, GRB>(rgbLed, 1); // GRB ordering is assumed
  FastLED.setBrightness(128);                           // Set global brightness to 50%
}

#ifdef TEST_FLAG
void Ambient::test()
{
  uint32_t ms = millis() % 255;
  rgbLed[0] = CHSV(ms, 150, 128);
  FastLED.show();
  FastLED.delay(4);
  //   Serial.println("Ambient loop");
}
#endif

void Ambient::loop()
{
}
