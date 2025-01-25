#pragma once
#include <Arduino.h>
class Animation
{
private:
    uint8_t frame_count;
    uint8_t current_frame = -1;
    const uint32_t *frame_sizes;
    const uint8_t **frames;

public:
    Animation(const uint8_t **frames, const uint32_t *frame_sizes, const uint8_t frame_count);
    void setup();
    void loop();
    static Animation test();
};
