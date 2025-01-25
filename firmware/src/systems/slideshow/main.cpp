#include "main.h"

FSAnimation fsanimation = FSAnimation("test");

void setup()
{
#ifdef ENABLE_LOGGING
    DebugLog::setup(BAUD_RATE);
#endif

    if (!SPIFFS.begin())
        Serial.println("SPIFFS initialisation failed!");

    Display::setup();
    fsanimation.setup();
}

void loop()
{
    fsanimation.loop();
    delay(5000);
}
