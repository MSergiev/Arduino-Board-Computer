// map_font.c
// Font type    : Full (95 characters)
// Font size    : 16x16 pixels
// Memory usage : 3044 bytes

#if defined(__AVR__)
    #include <avr/pgmspace.h>
    #define fontdatatype const uint8_t
#elif defined(__PIC32MX__)
    #define PROGMEM
    #define fontdatatype const unsigned char
#elif defined(__arm__)
    #define PROGMEM
    #define fontdatatype const unsigned char
#endif

fontdatatype map_font[3044] PROGMEM={
0x10,0x10,0x20,0x5F,
0x00,0x00,0x00,0xC0,0x00,0xE0,0x00,0xF8,0x00,0xFE,0x00,0xFF,0x03,0xFC,0x1F,0xF8,0x1F,0xF8,0x3F,0xF0,0x3F,0xF0,0x3F,0xF0,0x3F,0xF8,0x7F,0xFE,0x3F,0xFF,0x3F,0xFF,  // <space>
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x07,0xFC,0x7F,0xFE,0x9F,0xFF,  // !
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x7C,0x00,  // "
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,  // #
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // $
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x07,0x00,0x07,0x00,0x1F,0x00,0x3F,0x00,0x7F,0x00,0xFF,0x01,0xFF,  // %
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x0F,0x0F,0xFF,0x6F,0xFF,0xE7,0xFF,0xE1,0x7F,0xEC,0x3F,0xDF,0x9F,0x9F,0xE3,0x3F,0xF8,0x63,0xFF,0x88,0xFF,  // &
0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0xFF,0xC0,0xFF,0xF0,0xFF,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0xFF,0xF3,0x7F,0xE7,0x3F,0x9F,0x9F,0x3F,  // '
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xD8,0x40,0x1F,0xE0,0x7F,0xE0,0xFF,0xE0,0xFF,0xF0,0xFF,0xFC,0xFF,0xFF,0xFF,0xFF,  // (
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,  // )
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // *
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // +
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // -
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // .
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // /

0x3F,0xFF,0x1F,0xFE,0x0F,0xFE,0x07,0xFE,0x07,0xFC,0x07,0xFD,0x07,0xF3,0x07,0xE7,0x01,0xF7,0x00,0x67,0x00,0x0F,0x00,0x1F,0x00,0x07,0x00,0x07,0x00,0x03,0x00,0x03,  // 0
0x3F,0xFF,0x7F,0xFE,0xFF,0xFE,0xFF,0xFC,0xFF,0xFD,0xFF,0xFC,0xFF,0xFE,0xFF,0xE1,0xFF,0xEF,0xFF,0xDF,0xFF,0xDF,0xFF,0xDF,0xFF,0x9F,0xFF,0x3F,0xFF,0x1F,0xFF,0xE7,  // 1
0x7F,0xC0,0xFF,0xF0,0xFF,0xFD,0xFF,0xE0,0xFF,0xDB,0xFF,0xDF,0x7F,0xDF,0xFF,0xDF,0xFF,0xCF,0xFF,0xEF,0xFF,0xDF,0xFF,0x9F,0xFF,0x3F,0xFF,0x7F,0xFF,0x7F,0xFF,0x70,  // 2
0x0F,0x80,0x3F,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF9,0x8F,0xE0,0x27,0x9F,  // 3
0x40,0x00,0xE2,0x00,0xFE,0x80,0xFC,0xC3,0xFE,0xFD,0xFE,0xFD,0xFE,0xFD,0xFE,0xFC,0xFE,0xFE,0xF8,0xFF,0xF8,0xFF,0xCE,0xFF,0xC6,0x7F,0x17,0x7F,0x70,0x7F,0xF9,0xFF,  // 4
0x03,0xFF,0x0F,0xFF,0x7F,0xFC,0xFF,0xF0,0xFF,0xF7,0xFF,0xF7,0xFF,0xF2,0xFF,0xF0,0x7F,0xE7,0x7F,0xEF,0x7F,0xCF,0x87,0x9F,0xF0,0x0F,0xFF,0x8F,0xFF,0xC3,0xFF,0xF3,  // 5
0xFF,0x7F,0xFF,0x7F,0x7E,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFE,0x1F,0xFC,0xCF,0xFE,0xEF,0xF9,0xF1,0xFB,0xF9,0xFD,0xF9,0xE1,0xF8,0x09,0xFF,0xFB,0xFF,0xFB,0xFF,0xF9,  // 6
0xC1,0x3F,0xE4,0x3F,0xE7,0x9F,0x8F,0xE1,0x1F,0xF8,0x7F,0xE2,0xFF,0xEE,0xFF,0xE7,0xFF,0xE7,0xFF,0xEF,0xFF,0xCF,0xFF,0xEF,0xFF,0xEF,0xFF,0xCF,0xFF,0xDF,0xFF,0xEF,  // 7
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xBF,0xFF,0x1F,0xFF,0xC7,0xFF,0xF3,0xFF,0xF9,0xFF,0xFE,0x8E,0xFE,0x74,0xFF,0xF0,0xFF,0xF8,0xFF,0xF8,0xFF,0xF0,  // 8
0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xE0,0xFF,0xC0,0xFF,0xC0,0xE7,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 9
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // :
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ;
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // <
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // =
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // >
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ?

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x03,0x00,0x07,0x00,0x0F,0x00,0x0F,0x00,0x1F,0x00,0x07,0x07,0xE9,0x0F,0xFC,0x0F,0xFE,0x07,0xFF,  // @
0x3F,0xE7,0x1F,0xCF,0x4F,0x87,0x60,0x37,0xF4,0xF7,0xFF,0xF3,0xFF,0xFB,0xFF,0xF8,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFC,0x37,0xFD,0x80,0xFD,0xFD,0x79,0xFF,0x23,0xFF,  // A
0xFF,0x0F,0xFF,0xDF,0xFF,0xDF,0xFF,0xDF,0xFF,0x1F,0xEF,0x1F,0x40,0x1F,0x1E,0xCF,0xFF,0xEF,0xFF,0xE3,0xFF,0xF3,0xFF,0xF3,0x7F,0xFB,0x3F,0xFB,0x3F,0xF2,0x7F,0xF8,  // B
0xF0,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFE,0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xF8,0xFF,0x07,0x3F,  // C
0xFB,0xFF,0x9B,0xFF,0x87,0xFF,0x37,0xFF,0x79,0x9F,0x7C,0x1F,0x7F,0xC3,0xFF,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0x7F,0xFF,0xBF,0xFF,0x9F,0xFF,0xDE,0x79,  // D
0xFF,0xF3,0xFF,0xFB,0xFF,0xFB,0xFF,0xF3,0xFF,0xF3,0xFF,0xF3,0xFF,0xF9,0x7F,0xFD,0x3F,0xF9,0x7F,0xFE,0x7F,0xFC,0x3F,0xF9,0x9F,0xF3,0x9F,0xE7,0xBF,0xCF,0x80,0x1F,  // E
0xFF,0xFB,0xFF,0xF7,0xFF,0xE7,0xFF,0xEF,0xFF,0xE7,0xFF,0xCF,0xCF,0xDF,0xC0,0x3F,0xBF,0x7F,0x7F,0x1C,0xFF,0x03,0xFF,0xBF,0xFF,0x9F,0xFF,0xBF,0xFF,0xCF,0xFF,0xE7,  // F
0xFF,0xCF,0xFF,0x9F,0xFF,0x3F,0xFF,0x7F,0xFF,0xBF,0xFF,0x9F,0xFC,0x7F,0xFD,0x9F,0xFC,0x07,0x00,0xF9,0xFF,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,  // G
0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0x03,0x80,0xF9,0x80,0xFC,0x00,0xFF,0x80,0xFF,0x80,0xFF,0x80,  // H
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // I
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // J
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // K
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // L
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // M
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // N
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // O

0x07,0xFF,0x0F,0xFF,0x09,0xFF,0x01,0xFF,0x1C,0xFF,0x0E,0x7F,0x07,0x3F,0x03,0xBF,0x03,0xBF,0x03,0xCF,0x07,0xE6,0x0F,0xF1,0x0F,0xFF,0x1F,0xFF,0x3F,0xFF,0x1F,0xFF,  // P
0x83,0xFE,0xEF,0xFC,0xF7,0xFB,0xFB,0xF9,0xF3,0xFD,0xFC,0xFD,0xFE,0x79,0xFC,0x20,0xFD,0x88,0xFD,0xF8,0x0D,0xF8,0x81,0xFF,0xFA,0x7F,0xFF,0xBF,0xFF,0x9F,0xFF,0x9F,  // Q
0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF9,0xFF,0xF0,0xFC,0x47,0xFD,0x9F,0xFC,0xFF,0x7E,0x5F,0x7F,0x1F,0xFF,0xDF,0xFF,0x3F,0xFE,0x7F,0xFE,0x7F,0xFF,0x7F,0xF8,0x7F,  // R
0x9F,0x81,0xBF,0xFC,0x9F,0xFF,0xCF,0xFF,0x73,0xFF,0x53,0xFF,0x8F,0xFF,0xDF,0xFF,0xDF,0xFF,0xCF,0xFF,0xEF,0xFF,0xCF,0xFF,0xEF,0xFF,0xF7,0xFF,0xF7,0xFF,0xF7,0xFF,  // S
0x81,0x00,0x0F,0xF7,0xDF,0xFF,0xCF,0xFF,0xDF,0xFF,0xDF,0xFF,0xDF,0xFF,0xCF,0xFF,0xE1,0xFF,0xFC,0xFF,0xFC,0xFF,0xF8,0xFF,0xF8,0xFF,0xFB,0xFF,0xFB,0xFF,0xF9,0xFF,  // T
0x0E,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0x7F,0xFF,0x7F,0xFF,0x7F,0xFE,0x7F,0xFE,0xFF,0xFF,0x7F,0xFF,0x3F,0xFF,0x7F,0xFF,0x3E,0xFF,0xBF,0xFF,0x9F,0xFF,0xDF,0xFF,0xE2,  // U
0xFF,0xF7,0xFF,0xE3,0xFF,0xE5,0xFF,0xEC,0xFF,0x9E,0xF8,0x3E,0xF1,0xFE,0xF7,0xFF,0xE7,0xFF,0x8F,0xFF,0x7F,0xFF,0x3F,0xFF,0x3F,0xFF,0xBF,0xFF,0x7F,0xFF,0x7F,0xFF,  // V
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xF2,0x7F,0xE0,0x9F,0xFC,0xCF,0xE0,0x8F,0xE1,0x3F,0xEF,0x9F,0xFF,0xDF,0xFF,0xCF,0xFF,0xCF,0xFF,  // W
0xF8,0x00,0xF8,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xE0,0x00,0xF8,0x00,0xF8,0x00,0xFC,0x00,0xFC,0x00,0xFC,0x00,  // X
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // Y
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // Z
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // [
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // <backslash>
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ]
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ^
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // _

0x0F,0xFF,0x07,0xFF,0x07,0xFF,0x01,0xFD,0x00,0xF8,0x00,0x19,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // `
0xFF,0x3F,0xFF,0x8F,0xFF,0xE6,0xF0,0xF0,0xE6,0x31,0x0F,0x8F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0x3F,0xFF,  // a
0xF3,0xFF,0xC7,0xFF,0x0F,0xFF,0xEF,0xFF,0xEF,0xFF,0xE7,0xFF,0xE7,0xFF,0xE7,0xFF,0xEF,0xFF,0xEF,0xFF,0xEF,0xFF,0xEF,0xFF,0xE7,0xFF,0xF1,0xFF,0xFC,0xFF,0xFE,0x7A,  // b
0xF7,0xFF,0xF3,0xFF,0xF3,0xFF,0xE7,0xFF,0xEF,0xFF,0xEF,0xFF,0xE7,0xFF,0xF7,0xFF,0xEF,0xFF,0xEF,0xFF,0xC3,0xFF,0xD8,0x0F,0xBF,0xF7,0x7F,0xF7,0x7F,0xE7,0x7F,0xF3,  // c
0xF1,0xFF,0xF7,0xFF,0xF7,0xFF,0xF0,0x1C,0xFF,0xCD,0xFF,0xC3,0xFF,0x9F,0xFF,0x9F,0xFF,0xDF,0xFF,0xDF,0xFF,0xBF,0xFE,0x7F,0xFD,0x7F,0x9B,0x2F,0xA3,0x87,0x27,0xF9,  // d
0xFF,0xF0,0xBF,0xFE,0x3F,0xFE,0x0F,0xFD,0x86,0x3D,0xF2,0x8E,0xF9,0xEC,0xFF,0xF1,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,  // e
0x7F,0xFF,0x1F,0xFF,0xE1,0xFF,0xFE,0x7F,0xFF,0x7F,0xFF,0x7F,0xFE,0x7F,0xFE,0x7D,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xF0,0x00,0xE0,0x00,0xE0,0x00,0x40,0x00,  // f
0xEF,0xFF,0xEF,0xFF,0xEF,0xFF,0xE7,0xDF,0xF1,0x0F,0xE0,0x07,0xE0,0x03,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // g
0xFE,0x00,0xFF,0x00,0xFF,0x80,0xFF,0xC0,0xFF,0xC0,0xFF,0xE0,0xFF,0xF0,0xFB,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // h
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // i
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // j
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // k
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // l
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // m
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // n
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // o

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // p
0x3F,0xFF,0x3F,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFE,0x41,0xFC,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // q
0xFF,0x20,0xFF,0x8F,0xFF,0xCF,0xFF,0xEF,0xFF,0xDF,0xFF,0xC4,0xFF,0xC0,0xFF,0xC0,0xFC,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // r
0xFF,0xF6,0xFF,0xF1,0xFF,0xF9,0xFF,0xFF,0xFF,0xFF,0x78,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x7F,0x00,0x0F,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // s
0x2F,0xFC,0xF7,0xFF,0xF7,0xFF,0xF7,0xFF,0xF7,0xFF,0x8F,0xFF,0xBF,0xFF,0xC3,0xFF,0xE9,0xFF,0xF9,0xFF,0x79,0xFF,0x0B,0xFF,0x03,0xFF,0x01,0xFE,0x00,0xF0,0x00,0x00,  // t
0x3F,0xF0,0x9F,0xF0,0xDF,0xF0,0x98,0xF8,0x86,0xFC,0xFD,0xFC,0xFB,0xFE,0xF9,0xFC,0xFC,0xFC,0xFE,0xFC,0xFE,0xFC,0xFE,0x78,0xF8,0x80,0x00,0x00,0x00,0x00,0x00,0x00,  // u
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // v
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // w
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // x
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // y
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // z
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // |
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // }
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ~
};
