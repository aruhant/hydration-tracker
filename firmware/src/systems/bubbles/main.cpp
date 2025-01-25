#include "main.h"
#include "tank/tank.h"
#include "fish/fish.h"
#include "components/sprites/grass.h"
#include "components/fonts/scrollText.h"

ScrollText scrollText;

enum Mode
{
    IDLE = 0,
    GAME = 1,
    PUMP = 2
};
Mode mode = IDLE;
void setup()
{
#ifdef ENABLE_LOGGING
    DebugLog::setup(BAUD_RATE);
    Serial.println("Starting Bubbles...");
    delay(1000);
#endif

    if (!SPIFFS.begin())
        Serial.println("SPIFFS initialisation failed!");
    Display::setup();
    Button::setup();
    Beeper::setup();
    Ambient::setup();
    Image::setup();

    Display::tft.fillScreen(TANK_BG);
    Tank::setup(10);
    Fish::setup();
    GoldieGulp::setup();
    GoldieGulp::onGameOver([]()
                           { 
                            mode = IDLE; 
                            Tank::repaint(); });
    Button::button.setDoubleClickHandler([](Button2 &b)
                                         { Serial.println("Double click"); });
    Button::button.setClickHandler([](Button2 &b)
                                   { 
                                    Serial.println("Single click");
                                    if (mode !=GAME){
                                        mode = GAME;
                                        GoldieGulp::setup();
                                   } });
    Button::button.setTapHandler([](Button2 &b)
                                 { 
                                    Serial.println("Tap");
                                    if (mode==GAME)  GoldieGulp::jump(); });
    Button::button.setPressedHandler([](Button2 &b)
                                     { 
                                        Serial.println("Pressed");
                                        if (mode==IDLE) {mode=PUMP;} });
    Button::button.setReleasedHandler([](Button2 &b)
                                      { 
                                        Serial.println("Released");
                                        if (mode==PUMP) {
                                            Tank::endPump();
                                            Tank::repaint();
                                            Beeper::buzzer.setMelody(nullptr);
                                            mode=IDLE;} });
    scrollText.setup();
}

void displayTexts()
{
    Display::tft.setCursor(1, 1);
    Display::tft.setTextColor(TFT_WHITE);
    if (GoldieGulp::score != 0)
    {
        Display::tft.setTextSize(1);
        Display::tft.println("Score:");
        Display::tft.print(GoldieGulp::score);
    }
}

void paintGrass()
{
    uint8_t grass_start = TFT_HEIGHT - (TFT_HEIGHT / 10) * (Tank::refills >= 10 ? 10 : Tank::refills);

    for (uint16_t i = 0; i < grass_width; i++)
    {
        for (uint16_t j = 0; j < grass_height; j++)
        {
            uint16_t color = pgm_read_word(&grass[j * grass_width + i]);
            if (color != 0xe8c4)
                Display::tft.drawPixel(i, grass_start + j, color);
        }
    }
}

inline unsigned long lastPaintedAt = 0;
void loop()
{
    Button::loop();
    Beeper::loop();
    Ambient::loop();
    if (mode == IDLE)
    {
        if (millis() - lastPaintedAt < 1000 / 30)
            return;
        lastPaintedAt = millis();
        Tank::loop();
        Fish::loop();
        displayTexts();
        paintGrass();
    }
    else if (mode == GAME)
    {
        GoldieGulp::loop();
    }
    else if (mode == PUMP)
    {
        if (millis() - lastPaintedAt < 1000 / 30)
            return;
        lastPaintedAt = millis();
        Tank::pump();
        Tank::loop();
        Fish::loop();
    }
    // scrollText.loop();
}
