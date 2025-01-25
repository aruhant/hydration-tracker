#include "button.h"

Button2 Button::button = Button2(BUTTON_PIN);
void Button::setup()
{
    ;
}

void Button::loop()
{
    button.loop();
}

#ifdef TEST_FLAG
void Button::test()
{
    button.setClickHandler([](Button2 &b)
                           { Serial.println("Click"); });
    button.setDoubleClickHandler([](Button2 &b)
                                 { Serial.println("Double Click"); });
    button.setLongClickHandler([](Button2 &b)
                               { Serial.println("Long Click"); });
}
#endif