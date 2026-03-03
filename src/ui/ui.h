#ifndef UI_H
#define UI_H

#include <Arduino.h>

//mendefinisikan warna
const uint16_t BLACK = 0x0000;
const uint16_t BLUE = 0x001F;
const uint16_t RED = 0xF800;
const uint16_t GREEN = 0x07E0;
const uint16_t CYAN = 0x07FF;
const uint16_t MAGENTA = 0xF81F;
const uint16_t YELLOW = 0xFFE0;
const uint16_t WHITE = 0xFFFF;
const uint16_t PINK = 0xE8EC;

void text_align_center(String text,int posY,uint16_t color,uint8_t textSize);
void ui_text_print(String text,int posX,int posY,uint16_t color,uint8_t text_size,uint8_t text_font);
void ui_screen_fill(uint16_t color);
void ui_graphic_bitmap(int posX, int posY, uint8_t *bitmap, int width, int height, uint16_t color);
void ui_graphic_rectagle(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height, uint16_t color, bool filled);

#endif