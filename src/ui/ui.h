#ifndef UI_H
#define UI_H

#include <Arduino.h>

//mendefinisikan warna
extern const uint16_t BLACK;
extern const uint16_t BLUE;
extern const uint16_t RED;
extern const uint16_t GREEN;
extern const uint16_t CYAN;
extern const uint16_t MAGENTA;
extern const uint16_t YELLOW;
extern const uint16_t WHITE;
extern const uint16_t PINK;

void text_align_center(String text,int posY,uint16_t color,uint8_t textSize,uint8_t font);
void ui_text_print(String text,int posX,int posY,uint16_t color,uint8_t text_size,uint8_t text_font);
void ui_screen_fill(uint16_t color);
void ui_graphic_bitmap(int posX, int posY,const unsigned char bitmap[], int width, int height, uint16_t color);
void ui_graphic_rectagle(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height, uint16_t color, bool filled);

#endif