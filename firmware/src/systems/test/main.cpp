#include "main.h"

#ifdef ENABLE_ANIMATION
Animation animation = Animation::test();
#endif

#ifdef ENABLE_FSANIMATION
FSAnimation fsanimation = FSAnimation::test();
#endif

void setup()
{
#ifdef ENABLE_LOGGING
    DebugLog::setup(BAUD_RATE);
#ifdef TEST_FLAG
    DebugLog::test();
#endif
#endif

#ifdef ENABLE_FILESYSTEM
    if (!SPIFFS.begin())
        Serial.println("SPIFFS initialisation failed!");
#endif

#ifdef ENABLE_DISPLAY
    Display::setup();
#ifdef TEST_FLAG
    Display::test();
#endif
#endif

#ifdef ENABLE_BUTTON
    Button::setup();
#ifdef TEST_FLAG
    Button::test();
#endif
#endif

#ifdef ENABLE_BEEPER
    Beeper::setup();
#ifdef TEST_FLAG
    Beeper::test();
#endif
#endif

#ifdef ENABLE_AMBIENT
    Ambient::setup();
#ifdef TEST_FLAG
    Ambient::test();
#endif
#endif

#ifdef ENABLE_IMAGE
    Image::setup();
#ifdef TEST_FLAG
    Image::test();
#endif
#endif

#ifdef ENABLE_ANIMATION
    animation.setup();
#endif

#ifdef ENABLE_FSANIMATION
    fsanimation.setup();
#endif
}

void loop()
{
#ifdef ENABLE_DISPLAY
    //  display.test();
#endif
#ifdef ENABLE_LOGGING
    // logger.loop();
#endif
#ifdef ENABLE_BUTTON
    Button::loop();
#endif
#ifdef ENABLE_BEEPER
    Beeper::loop();
#endif
#ifdef ENABLE_AMBIENT
    Ambient::loop();
    Ambient::test();
#endif

#ifdef ENABLE_IMAGE
    Image::loop();
#endif

#ifdef ENABLE_FSANIMATION
    fsanimation.loop();
    delay(5000);
#endif

#ifdef ENABLE_ANIMATION
    animation.loop();
#endif
}
