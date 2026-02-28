#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "display.h"

#define TFT_CS        5
#define TFT_RST       4
#define TFT_DC        2
#define TFT_SCLK      18
#define TFT_MOSI      23
#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

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

//buat fungsi tambahan untuk display:
void text_align_center(String text,int posY,uint16_t color,uint8_t textSize){
  int16_t x1, y1;
  uint16_t w , h;

  tft.setTextSize(textSize);
  tft.getTextBounds(text, 0, posY, &x1, &y1, &w, &h);
  int posX = (tft.width()-w)/2;
  tft.setTextColor(color);
  tft.setCursor(posX,posY);
  tft.print(text);
}

void screen_setup(){
  tft.init(SCREEN_WIDTH, SCREEN_HEIGHT);
  tft.invertDisplay(0);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
}