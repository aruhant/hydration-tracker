#pragma once
#include <stdint.h>
#include <FastLED.h>

class Ambient
{
private:
    static CRGB rgbLed[];

public:
    static void setup();
    static void loop();
#ifdef TEST_FLAG
    static void test();
#endif
};
