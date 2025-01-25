#pragma once
#include <stdint.h>
#include <TFT_eSPI.h>

class Display
{
public:
    static TFT_eSPI tft;
    static void setup();
    static void loop();
#ifdef TEST_FLAG
    static void test();
#endif
};
