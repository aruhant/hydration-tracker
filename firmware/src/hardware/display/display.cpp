#include "display.h"
#include <Arduino.h>

TFT_eSPI Display::tft = TFT_eSPI();

void Display::setup()
{
  Serial.println("Display setup");
  pinMode(TFT_BL, OUTPUT);
  analogWrite(TFT_BL, 25);
  tft.begin();
}

void Display::loop()
{
  ;
}

#ifdef TEST_FLAG
void Display::test()
{
  tft.fillRect(3, 3, 90, 140, TFT_RED);
  tft.fillRect(33, 33, 90, 140, TFT_YELLOW);
  tft.fillRect(113, 113, 90, 140, TFT_BLUE);
  tft.fillRect(123, 123, 90, 140, TFT_CYAN);

  tft.setCursor(10, 10);
  tft.print("Hello World");
  Serial.println("Display loop");
}
#endif
