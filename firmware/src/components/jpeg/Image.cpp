#include "Image.h"
#include <TJpg_Decoder.h>
#include "hardware/display/Display.h"

inline bool render_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
  if (y >= Display::tft.height())
    return 0;
  Display::tft.pushImage(x, y, w, h, bitmap);
  return 1;
}
void Image::setup()
{
  Serial.println("Image setup");
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(render_output);
}

void Image::loop()
{
  ;
}

#ifdef TEST_FLAG
void Image::test()
{
  uint32_t t = millis();
  uint16_t w = 0, h = 0;
  TJpgDec.getJpgSize(&w, &h, testjpeg, sizeof(testjpeg));
  Serial.print("Width = ");
  Serial.print(w);
  Serial.print(", height = ");
  Serial.println(h);

  // Draw the image, top left at 0,0
  TJpgDec.drawJpg(0, 0, testjpeg, sizeof(testjpeg));
  t = millis() - t;
  Serial.print(t);
  Serial.println(" ms");
}

#endif