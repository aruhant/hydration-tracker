#include "goldie_gulp.h"
#include "hardware/display/display.h"
#include "components/sprites/goldy.h"
#include "systems/bubbles/tank/tank.h"
#include "hardware/beeper/beeper.h"
#include <TJpg_Decoder.h>

uint8_t GoldieGulp::current_frame = 0;
int16_t GoldieGulp::y = 0;
uint8_t GoldieGulp::oldY = 0;
int16_t GoldieGulp::speed = 1;
uint8_t GoldieGulp::frame_direction = 1;
uint16_t GoldieGulp::score = 0;
Obsticle GoldieGulp::obsticle = {TFT_WIDTH, 0, 100};
void (*GoldieGulp::gameOverCallback)() = nullptr;

void GoldieGulp::onGameOver(void (*callback)())
{
    gameOverCallback = callback;
}

GoldieGulp::GoldieGulp()
{
}

void GoldieGulp::eraseOldFish()
{
    uint16_t dh = abs(y - oldY);
    if (dh == 0)
        return;
    else if (dh > goldy_height)
        Display::tft.fillRect(GOLDIEGULP_X, oldY, goldy_width, goldy_height, TANK_WATER_COLOR);
    else
    {
        if (y > oldY)
            Display::tft.fillRect(GOLDIEGULP_X, oldY, goldy_width, dh, TANK_WATER_COLOR);
        else
            Display::tft.fillRect(GOLDIEGULP_X, y + goldy_height, goldy_width, dh, TANK_WATER_COLOR);
    }
}

void GoldieGulp::renderGameGoldie()
{
    eraseOldFish();
    for (uint8_t i = 0; i < goldy_width; i++)
    {
        for (uint8_t j = 0; j < goldy_height; j++)
        {
            uint16_t color = pgm_read_word(&goldy_frames[current_frame][j * goldy_width + i]);
            if (color != 2024)
                Display::tft.drawPixel(GOLDIEGULP_X + i, y + j, color);
            else
                Display::tft.drawPixel(GOLDIEGULP_X + i, y + j, TANK_WATER_COLOR);
        }
    }
}

void GoldieGulp::renderObsticle()
{
    obsticle.x -= GOLDIEGULP_OBSTICLE_SPEED;
    Display::tft.fillRect(obsticle.x + GOLDIEGULP_OBSTICLE_WIDTH, 0, GOLDIEGULP_OBSTICLE_SPEED, obsticle.opening_start, TANK_WATER_COLOR);
    Display::tft.fillRect(obsticle.x + GOLDIEGULP_OBSTICLE_WIDTH, obsticle.opening_end, GOLDIEGULP_OBSTICLE_SPEED, TFT_HEIGHT - obsticle.opening_end, TANK_WATER_COLOR);
    if (obsticle.x < -GOLDIEGULP_OBSTICLE_WIDTH)
    {
        score++;
        obsticle.x = TFT_WIDTH + random(0, 40);
        uint8_t type = random(0, 8);
        if (type < 1)
        {
            obsticle.opening_start = random(0, TFT_HEIGHT - GOLDIEGULP_OBSTICLE_MIN_GAP);
            obsticle.opening_end = random(obsticle.opening_start + GOLDIEGULP_OBSTICLE_MIN_GAP, TFT_HEIGHT);
        }
        else if (type < 4)
        {
            obsticle.opening_start = random(0, TFT_HEIGHT - GOLDIEGULP_OBSTICLE_MIN_GAP);
            obsticle.opening_end = TFT_HEIGHT - 10;
        }
        else
        {
            obsticle.opening_start = 0;
            obsticle.opening_end = random(GOLDIEGULP_OBSTICLE_MIN_GAP, TFT_HEIGHT);
        }
    }
    Display::tft.fillRect(obsticle.x, 0, GOLDIEGULP_OBSTICLE_WIDTH, obsticle.opening_start, 0x0019);
    Display::tft.fillRect(obsticle.x, obsticle.opening_end, GOLDIEGULP_OBSTICLE_WIDTH, TFT_HEIGHT - obsticle.opening_end, 0x0019);
}

void GoldieGulp::checkCollision()
{
    if (GOLDIEGULP_X + goldy_width > obsticle.x && GOLDIEGULP_X < obsticle.x + GOLDIEGULP_OBSTICLE_WIDTH)
    {
        if (y < obsticle.opening_start || y + goldy_height > obsticle.opening_end)
        {
            gameOverCallback();
            Beeper::buzzer.setMelody(&Beeper::melody1);
        }
    }
}

void GoldieGulp::renderScore()
{
    Display::tft.fillRect(0, 0, 20, 10, TANK_WATER_COLOR);
    Display::tft.setCursor(0, 0);
    Display::tft.setTextColor(TFT_WHITE);
    Display::tft.setTextSize(1);
    Display::tft.println(score);
}

void GoldieGulp::setup()
{
    Display::tft.fillScreen(TANK_WATER_COLOR);
    y = TFT_HEIGHT / 2;
    speed = 0;
    current_frame = 0;
    frame_direction = 1;
    score = 0;
    obsticle.x = TFT_WIDTH;
    obsticle.opening_start = 0;
    obsticle.opening_end = 100;
}

void GoldieGulp::jump()
{
    speed = (y * GOLDIEGULP_JUMP / TFT_HEIGHT) - 2 * GOLDIEGULP_GRAVITY;
}

inline unsigned long lastPaintedAt = 0;

void GoldieGulp::loop()
{

    if (millis() - lastPaintedAt < 1000 / 24)
        return;
    current_frame = (current_frame + frame_direction);
    if (current_frame == 20)
        frame_direction = -1;
    else if (current_frame == 6)
        frame_direction = 1;

    speed += GOLDIEGULP_GRAVITY;
    y += speed;
    if (y < 0)
        y = 0;
    else if (y > TFT_HEIGHT - goldy_height)
    {
        y = TFT_HEIGHT - goldy_height;
        speed = 0;
    }
    // Serial.print(y);
    // Serial.print(" ");
    // Serial.println(speed);
    renderObsticle();
    renderGameGoldie();
    renderScore();
    checkCollision();
    oldY = y;
    lastPaintedAt = millis();
}
