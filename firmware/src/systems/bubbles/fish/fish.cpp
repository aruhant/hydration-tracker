#include "fish.h"
#include "hardware/display/display.h"
#include "components/sprites/goldy.h"
#include "systems/bubbles/tank/tank.h"
#include "systems/bubbles/tank/tank.h"
#include <TJpg_Decoder.h>
#include "components/sprites/grass.h"

uint8_t Fish::current_frame = 0;
uint8_t Fish::x = 0;
uint8_t Fish::y = 0;
FishDirection Fish::speedX = RIGHT;
uint8_t Fish::speedY = 1;
const FishFrames *Fish::currentFrameSet = &moveFrames;

Fish::Fish()
{
}

void render(uint16_t x, uint16_t y, const uint16_t *bitmap, bool flip)
{
    for (uint16_t i = 0; i < goldy_width; i++)
    {
        for (uint16_t j = 0; j < goldy_height; j++)
        {
            uint16_t color =
                flip ? pgm_read_word(&bitmap[j * goldy_width + goldy_width - i - 1]) : pgm_read_word(&bitmap[j * goldy_width + i]);
            if (color != 2024)
                Display::tft.drawPixel(x + i, y + j, color);
            else
                Display::tft.drawPixel(x + i, y + j, TANK_WATER_COLOR);
        }
    }
}

void Fish::setup()
{
    Display::tft.setSwapBytes(false);
}

void Fish::loop()
{
    current_frame++;
    if (current_frame >= currentFrameSet->frames)
    {
        if (speedX == TURNING_LEFT)
        {
            speedX = LEFT;
            currentFrameSet = &moveFrames;
        }
        else if (speedX == TURNING_RIGHT)
        {
            speedX = RIGHT;
            currentFrameSet = &moveFrames;
        }
        current_frame = 0;
    }

    if (x >= TFT_WIDTH - goldy_width)
    {
        x--;
        speedX = TURNING_LEFT;
        currentFrameSet = &turnFrames;
        current_frame = 0;
    }
    else if (x <= grass_width)
    {
        x++;
        speedX = TURNING_RIGHT;
        currentFrameSet = &turnFrames;
        current_frame = 0;
    }

    // if ((y < Tank::waterLevel ) || y > TFT_HEIGHT - goldy_height)

    long r = random(1, 100);
    if (r == 1)
    {
        speedY = -1;
    }
    else if (r == 2)
    {
        speedY = 1;
    }
    else if ((r == 3) || (r == 4))
    {
        speedY = 0;
    }
    else if ((r == 5) && (x > TFT_WIDTH / 4 && x < TFT_WIDTH * 3 / 4))
    {
        if (speedX == RIGHT)
        {
            speedX = TURNING_LEFT;
            currentFrameSet = &turnFrames;
            current_frame = 0;
        }
        else if (speedX == LEFT)
        {
            speedX = TURNING_RIGHT;
            currentFrameSet = &turnFrames;
            current_frame = 0;
        }
    }

    if (y <= Tank::waterLevel)
    {
        speedY = 1;
    }
    else if (y > TFT_HEIGHT - goldy_height)
    {
        speedY = -1;
    }
    if (speedX == RIGHT || speedX == LEFT)
        x += speedX;
    y += speedY;
    render(x, y, goldy_frames[currentFrameSet->frameNumbers[current_frame]], speedX == LEFT || speedX == TURNING_LEFT);
    ;
}
