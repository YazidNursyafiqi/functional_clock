#include <Arduino.h>
#include "components/display/display.h"
#include "components/button/button.h"
#include "freertos/FreeRTOS.h"

void setup() {
  screen_setup();    //initialize/setup screen
  tft.fillRect(10, 10, 120, 120, WHITE);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  digitalWrite(13,HIGH);

  xTaskCreate(button_task,"button",1024,NULL,1,NULL); 
}

void loop() {
  
}