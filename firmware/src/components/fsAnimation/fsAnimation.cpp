#include "fsAnimation.h"
#include <TJpg_Decoder.h>
#include "hardware/display/display.h"

FSAnimation::FSAnimation(const char *folderName)
{
  this->folderName = folderName;
}

inline bool render_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
  if (y >= Display::tft.height())
    return 0;
  Display::tft.pushImage(x, y, w, h, bitmap);
  return 1;
}

void FSAnimation::setup()
{
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(render_output);
  Serial.println("FSAnimation setup");
}

void FSAnimation::loop()
{
  if (loadFile(currentFrame++))
    currentFrame = 1;
}

JRESULT FSAnimation::loadFile(uint8_t name)
{
  sprintf(fname, "/%s/%d.jpg", folderName, name);
  Serial.println(fname);
  return TJpgDec.drawFsJpg(0, 0, fname);
}

#ifdef TEST_FLAG
FSAnimation FSAnimation::test() { return FSAnimation("test"); }
#endif
