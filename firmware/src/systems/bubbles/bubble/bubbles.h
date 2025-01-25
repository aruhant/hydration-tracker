#pragma once
#include <Arduino.h>
#include "bubble.h"

#define BUBBLE_COUNT 10

class Bubbles
{
private:
    Bubble bubbles[BUBBLE_COUNT];
    uint8_t bubbleCount = 0;

public:
    Bubbles() {};
    void setBubbleRate(uint8_t speed);
    void loop(uint8_t overFill);
};