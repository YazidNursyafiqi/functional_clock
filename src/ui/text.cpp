#include <Arduino.h>
#include "components/display/display.h"
#include "ui.h"

//buat fungsi tambahan untuk display:
void text_align_center(String text,int posY,uint16_t color,uint8_t textSize,uint8_t font){
  int16_t x1, y1;
  uint16_t w , h;

  switch(font){
    case 0:
      tft.setFont();
      break;
    case 1:
      tft.setFont(&FreeSansBold12pt7b);
      break;
  }

  tft.setTextSize(textSize);
  tft.getTextBounds(text, 0, posY, &x1, &y1, &w, &h);
  int posX = (tft.width()-w)/2;
  tft.setTextColor(color);
  tft.setCursor(posX,posY);
  tft.print(text);
}

void ui_text_print(String text,int posX,int posY,uint16_t color,uint8_t text_size,uint8_t text_font){
  tft.setTextSize(text_size);
  tft.setTextColor(color);
  tft.setCursor(posX,posY);

  //memilih font
  switch(text_font){
    case 0:
      tft.setFont();
      break;
    case 1:
      tft.setFont(&FreeSansBold12pt7b);
      break;
  }

  tft.print(text);
}