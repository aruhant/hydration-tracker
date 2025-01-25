#include "tank.h"
#include "hardware/display/display.h"
#include "components/fonts/numberFont.h"
#include "hardware/beeper/beeper.h"

uint8_t Tank::waterLevel = 0;
ulong Tank::timeToEmpty = 0;
ulong Tank::timeFilled = 0;
uint8_t Tank::previous_waterLevel = 0;
uint16_t Tank::pumpRate = 0;
Bubbles *Tank::bubbles = nullptr;
uint8_t Tank::refills = 0;

double Tank::getFillFraction()
{
    return 1 - (double(waterLevel - waterLevel * pumpRate / 100.0)) / TFT_HEIGHT;
}

double Tank::getEmptyFraction()
{
    return (double(waterLevel - waterLevel * pumpRate / 100.0)) / TFT_HEIGHT;
}

void Tank::refill()
{
    refills++;
    setEmptyTime((timeToEmpty - timeFilled) / 60000);
}

void Tank::setEmptyTime(uint8_t mins)
{
    Serial.print("setEmptyTime :");
    Serial.println(mins);
    timeFilled = millis();
    timeToEmpty = timeFilled + (mins * 60 * 1000);
    previous_waterLevel = TANK_MAX_WATER;
    waterLevel = TANK_MAX_WATER;
    repaint();
}

void Tank::renderCount()
{
    for (uint32_t i = 0; i < largeLineFont_size[refills]; i++)
    {
        Display::tft.drawFastHLine(100 + largeLineFont[refills][i].xValue, 80 + largeLineFont[refills][i].yValue, largeLineFont[refills][i].lValue, 0x0016);
    }
}

void Tank::endPump()
{
    pumpRate = 0;
    bubbles->setBubbleRate(0);
}

void Tank::pump()
{
    if (waterLevel < TANK_MAX_WATER + 4)
        return endPump();
    if (pumpRate >= 10 * 10)
    {
        pumpRate = 0;
        refill();
    }
    else
    {
        Buzzer::Melody_t melody;
        melody.nbNotes = 1;
        melody.duration[0] = 100;
        melody.frequency[0] = 50 + pumpRate;
        Beeper::buzzer.setMelody(&melody);
        bubbles->setBubbleRate(pumpRate / 10);
    }
    pumpRate++;
}

void Tank::repaint()
{
    Display::tft.fillRect(0, 0, TFT_WIDTH, waterLevel, TANK_BG);
    Display::tft.fillRect(0, waterLevel, TFT_WIDTH, TFT_HEIGHT, TANK_WATER_COLOR);
}

void Tank::setup(uint8_t mins)
{
    bubbles = new Bubbles();
    setEmptyTime(mins);
}

void Tank::loop()
{
    renderCount();
    bubbles->loop(pumpRate / 10);
    if (pumpRate > 0)
    {
        uint8_t newWaterLevel = waterLevel * (1.0 - pumpRate / 100.0);
        Display::tft.fillRect(0, newWaterLevel, TFT_WIDTH, previous_waterLevel - newWaterLevel, TANK_WATER_COLOR);
        previous_waterLevel = newWaterLevel;
    }
    else
    {
        if (waterLevel >= TANK_MIN_WATER)
        {
            waterLevel = TANK_MIN_WATER;
            return;
        }
        waterLevel = map(millis(), timeFilled, timeToEmpty, TANK_MAX_WATER, TANK_MIN_WATER);

        if (waterLevel == previous_waterLevel)
            return;

        previous_waterLevel = waterLevel;
        Display::tft.fillRect(0, 0, TFT_WIDTH, waterLevel, TANK_BG);
    }
}
