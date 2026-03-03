#include <Arduino.h>
#include "components/display/display.h"
#include "ui.h"

void ui_graphic_bitmap(int posX, int posY, uint8_t *bitmap, int width, int height, uint16_t color){
    tft.drawBitmap(posX,posY,bitmap,width,height,color);
}   

void ui_graphic_rectagle(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height, uint16_t color, bool filled){
    if(filled){
        tft.fillRect(posX,posY,width,height,color);
    }else{
        tft.drawRect(posX,posY,width,height,color);
    }
}