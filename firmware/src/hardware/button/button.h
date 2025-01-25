#pragma once
#include "Button2.h"

class Button
{
public:
    static Button2 button;

public:
    static void setup();
    static void loop();
#ifdef TEST_FLAG
    static void test();
#endif
};