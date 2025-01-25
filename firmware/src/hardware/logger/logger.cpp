#include <Arduino.h>
#include "logger.h"
void DebugLog::setup(unsigned long baud)
{
    Serial.begin(baud);
    delay(1000);
    Serial.println("Logger setup");
}
void DebugLog::loop()
{
    ;
}

void DebugLog::log(const char *message)
{
    Serial.println(message);
}
void DebugLog::warn(const char *message)
{
    Serial.println(String("*** ") + message + " ***");
}

#ifdef TEST_FLAG
void DebugLog::test()
{
    Serial.println("Logger test");
}
#endif