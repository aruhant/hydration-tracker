#pragma once
#include <Arduino.h>
class Bubble
{
public:
    uint8_t x, y, radius, speed;
    uint32_t color;
    Bubble(uint8_t x, uint8_t y, uint8_t radius, uint8_t speed, uint32_t color);
    Bubble() { init(); };
    void loop(uint8_t count, uint8_t overFill);

private:
    void init();
    void drawBubble(uint8_t count, double overFill);
};