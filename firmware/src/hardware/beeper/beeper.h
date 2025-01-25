#pragma once
#include <Buzzer.h>

class Beeper
{
private:
public:
    static Buzzer buzzer;
    static Buzzer::Melody_t melody1;
    static void setup();
    static void loop();
#ifdef TEST_FLAG
    static Buzzer::Melody_t melodyTest;
    static void test();
#endif
};