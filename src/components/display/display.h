#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <Adafruit_ST7789.h>
//tambah font 
#include <Fonts/FreeSansBold12pt7b.h>

//definisikan warna
extern const uint16_t BLACK;
extern const uint16_t BLUE;
extern const uint16_t RED;
extern const uint16_t GREEN;
extern const uint16_t CYAN;
extern const uint16_t MAGENTA;
extern const uint16_t YELLOW;
extern const uint16_t WHITE;
extern const uint16_t PINK;

extern Adafruit_ST7789 tft;

extern void text_align_center(String text,int posY,uint16_t color,uint8_t textSize);
extern void screen_setup();

#endif