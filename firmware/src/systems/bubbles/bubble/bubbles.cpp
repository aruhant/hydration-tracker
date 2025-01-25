#include <Arduino.h>
#include "bubbles.h"

void Bubbles::setBubbleRate(uint8_t speed)
{
    bubbleCount = speed;
}

void Bubbles::loop(uint8_t overFill)
{
    for (uint8_t i = 0; i < BUBBLE_COUNT; i++)
        bubbles[i].loop(bubbleCount, overFill);
}