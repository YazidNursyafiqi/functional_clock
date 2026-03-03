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
#define SCREEN_BACKLIGHT_PIN 13

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);





//function to set backlight display condition on or off
void screen_backlight_set(bool is_on){
  digitalWrite(SCREEN_BACKLIGHT_PIN,is_on);
}

//setup screen at the first time , usualy used after boot
void screen_setup(){
  screen_backlight_set(1);
  tft.init(SCREEN_WIDTH, SCREEN_HEIGHT);
  tft.invertDisplay(0);
  tft.setRotation(1);
  tft.fillScreen(0x0000);
}