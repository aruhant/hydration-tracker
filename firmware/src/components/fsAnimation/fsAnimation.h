#pragma once
#include <Arduino.h>
#include <TJpg_Decoder.h>
class FSAnimation
{
private:
    const char *folderName;
    uint8_t currentFrame = 1;
    char fname[36];
    JRESULT loadFile(uint8_t name);

public:
    void loop();
    FSAnimation(const char *);
    void setup();
    static FSAnimation test();
};
