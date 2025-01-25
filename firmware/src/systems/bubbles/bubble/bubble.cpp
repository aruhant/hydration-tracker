#include "bubble.h"
#include <Arduino.h>
#include "hardware/display/display.h"
#include "systems/bubbles/tank/tank.h"

void Bubble::init()
{
    double fillFraction = Tank::getFillFraction();
    y = TFT_HEIGHT + radius;
    x = random(0, TFT_HEIGHT);
    radius = 2 + random(4, 10) * fillFraction;
    speed = 1 + random(2, 10) * fillFraction;
    // Create a random shade of blue
    color = Display::tft.color565(100, random(100, 215), random(100, 255));
}

Bubble::Bubble(uint8_t x, uint8_t y, uint8_t radius, uint8_t speed, uint32_t color)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->speed = speed;
    this->color = color;
}

uint8_t primes[] = {31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

void Bubble::drawBubble(uint8_t num, double overFill)
{
    if (num == 0)
    {
        Display::tft.drawCircle(x, y, radius, TANK_WATER_COLOR);
        y -= speed;
        if (y <= Tank::waterLevel)
            init();
        Display::tft.drawCircle(x, y, radius, color);
    }
    else
    {
        uint16_t x = ((this->x) * primes[num]) % TFT_WIDTH;
        uint16_t y = overFill * Tank::waterLevel + (this->y * primes[num]) % (TFT_HEIGHT);
        uint16_t yOld = overFill * Tank::waterLevel + ((this->y + speed) * primes[num]) % (TFT_HEIGHT);
        Display::tft.drawCircle(x, yOld, radius, TANK_WATER_COLOR);
        Display::tft.drawCircle(x, y, radius, color);
    }
}

void Bubble::loop(uint8_t count, uint8_t overFill)
{
    for (uint8_t i = 0; i <= count; i++)
        drawBubble(i, 1.0 - overFill / 10.0);
}