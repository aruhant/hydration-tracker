/*  Create C arrays from jpeg images using this online tool:
    http://tomeko.net/online_tools/file_to_hex.php?lang=en

    If needed, first resize and crop to an appropriate width and height
    to suit your display with an image editing program such as IrfanView.
    
    You can also change the image "quality" to reduce the file size.
    
    Paste the array into a new tab, top and tail the array from the
    tool to look like the one below with:

    #include <pgmspace.h>
    const uint8_t name[] PROGMEM = {

    to start and and end with:

   };

    Change the name of the array


*/

#include <pgmspace.h>
const uint8_t testjpeg[] PROGMEM = {
    0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01, 0x01, 0x00, 0x00, 0x48, 
0x00, 0x48, 0x00, 0x00, 0xFF, 0xDB, 0x00, 0x43, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDB, 0x00, 0x43, 0x01, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 
0x00, 0x11, 0x08, 0x00, 0xF0, 0x00, 0xF0, 0x03, 0x01, 0x22, 0x00, 0x02, 0x11, 0x01, 0x03, 0x11, 
0x01, 0xFF, 0xC4, 0x00, 0x18, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x03, 0xFF, 0xC4, 0x00, 0x16, 0x10, 
0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x31, 0xFF, 0xC4, 0x00, 0x16, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xC4, 0x00, 0x18, 0x11, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x31, 0x02, 0x41, 0xFF, 0xDA, 0x00, 0x0C, 0x03, 0x01, 0x00, 0x02, 0x11, 0x03, 0x11, 
0x00, 0x3F, 0x00, 0xF4, 0x01, 0x98, 0x01, 0x2E, 0x32, 0x00, 0x0A, 0x25, 0x54, 0xA5, 0xCE, 0x8D, 
0xC0, 0x03, 0x01, 0x9B, 0xAD, 0x31, 0x75, 0x2A, 0xC0, 0x01, 0x50, 0x03, 0xE7, 0xD3, 0xE7, 0xD0, 
0x02, 0x21, 0x15, 0x02, 0xB0, 0x02, 0x29, 0x51, 0x6A, 0x1F, 0x38, 0x17, 0x40, 0x08, 0x50, 0x00, 
0xBA, 0xA0, 0x08, 0xCE, 0x80, 0x19, 0x80, 0x12, 0xE3, 0x20, 0x00, 0xA2, 0x55, 0x4A, 0x5C, 0xE8, 
0xDC, 0x00, 0x30, 0x18, 0xBA, 0xDB, 0x17, 0x52, 0xAC, 0x00, 0x15, 0x00, 0x3E, 0x7D, 0x3E, 0x7D, 
0x00, 0x22, 0x11, 0x50, 0x2B, 0x00, 0x22, 0x95, 0x16, 0xA1, 0xF3, 0x81, 0x74, 0x00, 0x85, 0x00, 
0x0B, 0xAA, 0x00, 0x8C, 0xE8, 0x01, 0x98, 0x01, 0x2E, 0x32, 0x00, 0x0A, 0x25, 0x54, 0xA5, 0xCE, 
0x8D, 0xC0, 0x03, 0x01, 0x8B, 0xAD, 0xB1, 0x75, 0x2A, 0xC0, 0x01, 0x50, 0x03, 0xE7, 0xD3, 0xE7, 
0xD0, 0x02, 0x21, 0x15, 0x02, 0xB0, 0x02, 0x29, 0x51, 0x6A, 0x1F, 0x38, 0x17, 0x40, 0x08, 0x50, 
0x00, 0xBA, 0xA0, 0x08, 0xCE, 0x80, 0x19, 0x80, 0x12, 0xE3, 0x20, 0x00, 0xA2, 0x55, 0x4A, 0x5C, 
0xE8, 0xDC, 0x00, 0x30, 0x18, 0xBA, 0xDB, 0x17, 0x52, 0xAC, 0x00, 0x15, 0x00, 0x3E, 0x7D, 0x3E, 
0x7D, 0x00, 0x22, 0x11, 0x50, 0x2B, 0x00, 0x22, 0x95, 0x16, 0xA1, 0xF3, 0x81, 0x74, 0x00, 0x85, 
0x00, 0x0B, 0xAA, 0x00, 0x8C, 0xE8, 0x01, 0x98, 0x01, 0x2E, 0x32, 0x00, 0x0A, 0x25, 0x54, 0xA5, 
0xCE, 0x8D, 0xC0, 0x03, 0x01, 0x8B, 0xAD, 0xB1, 0x75, 0x2A, 0xC0, 0x01, 0x50, 0x03, 0xE7, 0xD3, 
0xE7, 0xD0, 0x02, 0x21, 0x15, 0x02, 0xB0, 0x02, 0x29, 0x51, 0x6A, 0x1F, 0x38, 0x17, 0x40, 0x08, 
0x50, 0x00, 0xBA, 0xA0, 0x08, 0xCE, 0x80, 0x19, 0x80, 0x12, 0xE3, 0x20, 0x00, 0xA2, 0x55, 0x4A, 
0x5C, 0xE8, 0xDC, 0x00, 0x30, 0x18, 0xBA, 0xDB, 0x17, 0x52, 0xAC, 0x00, 0x15, 0x00, 0x3E, 0x7D, 
0x3E, 0x7D, 0x00, 0x22, 0x11, 0x50, 0x2B, 0x00, 0x22, 0x95, 0x16, 0xA1, 0xF3, 0x81, 0x74, 0x00, 
0x85, 0x00, 0x0B, 0xAA, 0x00, 0x8C, 0xE8, 0x01, 0x98, 0x01, 0x2E, 0x32, 0x00, 0x0A, 0x25, 0x54, 
0xA5, 0xCE, 0x8D, 0xC0, 0x03, 0x01, 0x8B, 0xAD, 0xB1, 0x75, 0x2A, 0xC0, 0x01, 0x50, 0x03, 0xE7, 
0xD3, 0xE7, 0xD0, 0x02, 0x21, 0x15, 0x02, 0xB0, 0x02, 0x29, 0x51, 0x6A, 0x1F, 0x38, 0x17, 0x40, 
0x08, 0x50, 0x00, 0xBA, 0xA0, 0x08, 0xCE, 0x80, 0x19, 0x80, 0x12, 0xE3, 0x20, 0x00, 0xA2, 0x55, 
0x4A, 0x5C, 0xE8, 0xDC, 0x00, 0x30, 0x18, 0xBA, 0xDB, 0x17, 0x52, 0xAC, 0x00, 0x15, 0x00, 0x3E, 
0x7D, 0x3E, 0x7D, 0x00, 0x22, 0x11, 0x50, 0x2B, 0x00, 0x22, 0x95, 0x16, 0xA1, 0xF3, 0x81, 0x74, 
0x00, 0x85, 0x00, 0x0B, 0xAA, 0x00, 0x8C, 0xE8, 0x01, 0x98, 0x01, 0x2E, 0x32, 0x00, 0x0A, 0x25, 
0x54, 0xA5, 0xCE, 0x8D, 0xC0, 0x03, 0x01, 0x8B, 0xAD, 0xB1, 0x75, 0x2A, 0xC0, 0x01, 0x50, 0x03, 
0xE7, 0xD3, 0xE7, 0xD0, 0x02, 0x21, 0x15, 0x02, 0xB0, 0x02, 0x29, 0x51, 0x6A, 0x1F, 0x38, 0x17, 
0x40, 0x08, 0x50, 0x00, 0xBA, 0xA0, 0x08, 0xCE, 0x80, 0x19, 0x80, 0x12, 0xE3, 0x20, 0x00, 0xA2, 
0x55, 0x4A, 0x5C, 0xE8, 0xDC, 0x00, 0x30, 0x18, 0xBA, 0xDB, 0x17, 0x52, 0xAC, 0x00, 0x15, 0x00, 
0x3E, 0x7D, 0x3E, 0x7D, 0x00, 0x22, 0x11, 0x50, 0x2B, 0x00, 0x22, 0x95, 0x16, 0xA1, 0xF3, 0x81, 
0x74, 0x00, 0x85, 0x00, 0x0B, 0xAA, 0x00, 0x8C, 0xE8, 0x01, 0x98, 0x01, 0x2E, 0x32, 0x00, 0x0A, 
0x25, 0x54, 0xA5, 0xCE, 0x8D, 0xC0, 0x03, 0x01, 0x8B, 0xAD, 0xB1, 0x75, 0x2A, 0xC0, 0x01, 0x50, 
0x03, 0xE7, 0xD3, 0xE7, 0xD0, 0x02, 0x21, 0x15, 0x02, 0xB0, 0x02, 0x29, 0x51, 0x6A, 0x1F, 0x38, 
0x17, 0x40, 0x08, 0x50, 0x00, 0xBA, 0xA0, 0x08, 0xCE, 0x80, 0x19, 0x80, 0x12, 0xE3, 0x20, 0x00, 
0xA2, 0x55, 0x4A, 0x5C, 0xE8, 0xDC, 0x00, 0x30, 0x18, 0xBA, 0xDB, 0x17, 0x52, 0xAC, 0x00, 0x15, 
0x00, 0x3E, 0x7D, 0x3E, 0x7D, 0x00, 0x22, 0x11, 0x50, 0x2B, 0x00, 0x22, 0x95, 0x16, 0xA1, 0xF3, 
0x81, 0x74, 0x00, 0x85, 0x00, 0x0B, 0xAA, 0x00, 0x8C, 0xE8, 0x01, 0x98, 0x01, 0x2E, 0x32, 0x00, 
0x0A, 0x25, 0x54, 0xA5, 0xCE, 0x8D, 0xC0, 0x03, 0x01, 0x8B, 0xAD, 0xB1, 0x75, 0x2A, 0xC0, 0x01, 
0x50, 0x03, 0xE7, 0xD3, 0xE7, 0xD0, 0x02, 0x21, 0x15, 0x02, 0xB0, 0x02, 0x29, 0x51, 0x6A, 0x1F, 
0x38, 0x17, 0x40, 0x08, 0x50, 0x00, 0xBA, 0xA0, 0x08, 0xCE, 0x80, 0x19, 0x80, 0x12, 0xE3, 0x20, 
0x00, 0xA2, 0x55, 0x4A, 0x5C, 0xE8, 0xDC, 0x00, 0x30, 0x18, 0xBA, 0xDB, 0x17, 0x52, 0xAC, 0x00, 
0x15, 0x00, 0x3E, 0x7D, 0x3E, 0x7D, 0x00, 0x22, 0x11, 0x50, 0x2B, 0x00, 0x22, 0x95, 0x16, 0xA1, 
0xF3, 0x81, 0x74, 0x00, 0x85, 0x00, 0x0B, 0xAA, 0x00, 0x8C, 0xE8, 0x01, 0x98, 0x01, 0x2E, 0x32, 
0x00, 0x0A, 0x25, 0x54, 0xA5, 0xCE, 0x8D, 0xC0, 0x03, 0x01, 0x8B, 0xAD, 0xB1, 0x75, 0x2A, 0xC0, 
0x01, 0x50, 0x03, 0xE7, 0xD3, 0xE7, 0xD0, 0x02, 0x21, 0x15, 0x02, 0xB0, 0x02, 0x29, 0x51, 0x6A, 
0x1F, 0x38, 0x17, 0x40, 0x08, 0x50, 0x00, 0xBA, 0xA0, 0x08, 0xCF, 0xFF, 0xD9
};