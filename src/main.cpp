#include <Arduino.h>
#include "components/display/display.h"
#include "components/button/button.h"
#include "components/time/time.h"
#include "components/homepage/homepage.h"

//multithreading components
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

//declare all semaphore variables
SemaphoreHandle_t xbutton;
SemaphoreHandle_t xtime;


void setup() {
  screen_setup();    //initialize/setup screen
  tft.fillRect(10, 10, 120, 120, WHITE);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  digitalWrite(13,HIGH);

  //semaphore mutex setup
  xbutton = xSemaphoreCreateMutex();
  xtime = xSemaphoreCreateMutex();

  //time initialization
  time_setup();

  //running startup programs
  xTaskCreate(button_task,"button",2048,NULL,1,NULL); 
  xTaskCreate(homepage_task,"homepage",4096,NULL,1,NULL); 

}

void loop() {
  
}