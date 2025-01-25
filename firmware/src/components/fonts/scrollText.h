#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>
#include "hardware/display/display.h"

class ScrollText
{
private:
    static uint8_t routine;
    static int8_t swap_routine;
    static uint8_t tcount;
    static uint8_t changecol;
    static uint8_t scrolldelay;
    static unsigned long startMillis;
    static unsigned long nowMillis;
    static uint16_t array_pos;
    static String lcdscroller;
    static char string_array[];
    static String blank;
    static TFT_eSprite stext; // Sprite object stext2

    static void scrolltext();
    static void scrolltext2();

public:
    static void setup();
    static void loop();
};