#pragma once
class DebugLog
{
public:
    static void setup(unsigned long);
    static void loop();
    static void log(const char *);
    static void warn(const char *);
#ifdef TEST_FLAG
    static void test();
#endif
};