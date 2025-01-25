#pragma once
#include "Arduino.h"
#include "systems/bubbles/bubble/bubbles.h"
#include "hardware/display/display.h"

#define TANK_BG 0x000003
#define TANK_WATER_COLOR TFT_BLUE
#define TANK_MAX_WATER 0
#define TANK_MIN_WATER 200

class Tank
{
private:
    static uint8_t previous_waterLevel;
    static ulong timeToEmpty, timeFilled;
    static Bubbles *bubbles;
    static void renderCount();

public:
    static uint8_t refills;
    static uint16_t pumpRate;
    double static getFillFraction();
    double static getEmptyFraction();
    static void repaint();
    static void refill();
    static void pump();
    static void endPump();
    static uint8_t waterLevel;

    static void loop();
    static void setup(uint8_t mins);
    static void setEmptyTime(uint8_t mins);
};
