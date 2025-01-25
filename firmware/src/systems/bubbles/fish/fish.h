#pragma once
#include "Arduino.h"
#include "hardware/display/display.h"
enum FishDirection
{
    TURNING_LEFT = -2,
    LEFT = -1,
    NOT_MOVING = 0,
    RIGHT = 1,
    TURNING_RIGHT = 2
};

struct FishFrames
{
    const uint8_t frames;
    const uint8_t *frameNumbers;
};

const FishFrames moveFrames = {15, (uint8_t[15]){6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}};
const FishFrames turnFrames = {26, (uint8_t[26]){59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84}};
class Fish
{
private:
    static uint8_t current_frame, x, y, speedY;
    static FishDirection speedX;
    static const FishFrames *currentFrameSet;

public:
    Fish();
    static void loop();
    static void setup();
};
