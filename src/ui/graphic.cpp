#include <Arduino.h>
#include "components/display/display.h"
#include "ui.h"

const uint16_t BLACK = 0x0000;
const uint16_t BLUE = 0x001F;
const uint16_t RED = 0xF800;
const uint16_t GREEN = 0x07E0;
const uint16_t CYAN = 0x07FF;
const uint16_t MAGENTA = 0xF81F;
const uint16_t YELLOW = 0xFFE0;
const uint16_t WHITE = 0xFFFF;
const uint16_t PINK = 0xE8EC;

void ui_graphic_bitmap(int posX, int posY, const unsigned char bitmap[], int width, int height, uint16_t color){
    tft.drawBitmap(posX,posY,bitmap,width,height,color);
}   

void ui_graphic_rectagle(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height, uint16_t color, bool filled){
    if(filled){
        tft.fillRect(posX,posY,width,height,color);
    }else{
        tft.drawRect(posX,posY,width,height,color);
    }
}