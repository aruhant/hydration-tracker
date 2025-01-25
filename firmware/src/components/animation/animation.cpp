#include "animation.h"
#include "hardware/display/display.h"
#include <TJpg_Decoder.h>

#ifdef TEST_FLAG
#include "blue.h"
#endif

Animation::Animation(const uint8_t **frames, const uint32_t *frame_sizes, const uint8_t frame_count)
{
    this->frames = frames;
    this->frame_sizes = frame_sizes;
    this->frame_count = frame_count;
}

inline bool render_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
    if (y >= Display::tft.height())
        return 0;
    Display::tft.pushImage(x, y, w, h, bitmap);
    return 1;
}

void Animation::setup()
{
    TJpgDec.setSwapBytes(true);
    TJpgDec.setCallback(render_output);
    Serial.println("Animation setup");
}

void Animation::loop()
{
    current_frame = (current_frame + 1) % frame_count;
    TJpgDec.drawJpg(0, 0, frames[current_frame], frame_sizes[current_frame]);
}

#ifdef TEST_FLAG
Animation Animation::test()
{
    return Animation(blue, blue_sizes, blue_frames);
}
#endif