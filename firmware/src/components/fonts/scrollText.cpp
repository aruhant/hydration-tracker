#include "scrollText.h"
#include "hardware/display/display.h"

#define fontwidth 16

uint16_t ScrollText::array_pos = 0; // Start text for scroller
uint8_t ScrollText::changecol = 0;
unsigned long ScrollText::nowMillis = 0;
unsigned long ScrollText::startMillis = 0; // global for scrolling text
uint8_t ScrollText::scrolldelay = 20;      // the value is a number of milliseconds
uint8_t ScrollText::tcount = 0;
String ScrollText::blank;
int8_t ScrollText::swap_routine = 0;
uint8_t ScrollText::routine = 0;
String ScrollText::lcdscroller;
char ScrollText::string_array[256];
TFT_eSprite ScrollText::stext = TFT_eSprite(&Display::tft); // Sprite object stext2

void ScrollText::setup(void)
{
    stext.setTextWrap(false); // Don't wrap text to next line
    stext.setTextSize(3);     // larger letters
    startMillis = millis();
}

void ScrollText::loop()
{
    nowMillis = millis(); // get the current "time" (actually the number of milliseconds since the program started)
    switch (routine)
    {
    case 0:
        blank = " ---";
        lcdscroller = "Test" + blank;
        scrolltext();
        break;
    case 1:
        blank = " ***";
        lcdscroller = "Test2" + blank;
        scrolltext2();
        break;
    }
}

void ScrollText::scrolltext()
{
    uint16_t arraysize = lcdscroller.length() + 1;    // added extra character for null at end of string
    char string_array[arraysize];                     // Prepare the character array (the buffer)
    lcdscroller.toCharArray(string_array, arraysize); // Copy it over

    if (array_pos >= arraysize)
    {
        array_pos = 0;
    }
    if (changecol >= arraysize)
    {
        changecol = 0;
        stext.setTextColor(random(0x4000, 0xFFFF), TFT_TRANSPARENT);
        swap_routine++;
        if (swap_routine >= 3)
        {
            swap_routine = 0; // reset swap routine
            routine = 1;      // jump to scrolltext2
        }
    }
    stext.createSprite(256, 32); // Screen width + width of the font
    stext.fillSprite(TFT_TRANSPARENT);

    if (nowMillis - startMillis >= scrolldelay)
    {
        stext.pushSprite(0, 34); // location to draw the sprite
        stext.scroll(-1);        // scroll stext 1 pixel left, up/down default is 0

        tcount--;
        if (tcount <= 0)
        {
            char x = string_array[array_pos];
            tcount = fontwidth;                           // once this pixel count is reached redraw the text
            stext.drawString(String(x), TFT_WIDTH, 0, 1); // draw string into sprite at location.
            array_pos++;
            changecol++;
        }
        startMillis = nowMillis;
    }
}

void ScrollText::scrolltext2()
{
    uint16_t arraysize = lcdscroller.length() + 1;
    char string_array[arraysize];                     // Prepare the character array (the buffer)
    lcdscroller.toCharArray(string_array, arraysize); // Copy it over

    if (array_pos >= arraysize)
    {
        array_pos = 0;
    }
    if (changecol >= arraysize)
    {
        changecol = 0;
        stext.setTextColor(random(0x4000, 0xFFFF), TFT_TRANSPARENT);
        swap_routine++;
        if (swap_routine >= 3)
        {
            swap_routine = 0; // reset swap routine
            routine = 0;      // jump to scrolltext
        }
    }

    if (nowMillis - startMillis >= scrolldelay)
    {
        stext.pushSprite(0, 34); // location to put the scrolling text
        stext.scroll(-1);        // scroll stext 1 pixel left, up/down default is 0

        tcount--;
        if (tcount <= 0)
        {
            char x = string_array[array_pos];
            tcount = fontwidth;                           // once this pixel count is reached redraw the text
            stext.drawString(String(x), TFT_WIDTH, 0, 1); // draw sprite at location.
            array_pos++;
            changecol++;
        }
        startMillis = nowMillis;
    }
}