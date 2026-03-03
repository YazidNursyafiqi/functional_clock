#include <Arduino.h>
#include "components/display/display.h"
#include "ui.h"

void ui_screen_fill(uint16_t color){
    tft.fillScreen(color);
}