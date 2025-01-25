#pragma once
#include <Arduino.h>
class Image
{
public:
    static void setup();
    static void loop();
    static void test();
};

#ifdef TEST_FLAG
#include "testjpeg.h"
#endif