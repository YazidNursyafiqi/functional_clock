#include <Arduino.h>
#include <ui/ui.h>
#include <TimeLib.h>

String weekday_to_string(){
    
}

void dashboard_page(bool &rendered){
    //setup  function
    if(!rendered){
        rendered = true;
    }



    //loop function
}


void home_screen_setup(){
//   tft.fillScreen(BLACK);
ui_screen_fill(BLACK);

//   tft.setTextColor(WHITE);
//   tft.setTextSize(8);
//   tft.setTextWrap(false);
//angka menit
// tft.setCursor(169, 33);
// tft.print((minute() < 10)?"0" + String(minute()): String(minute()));
ui_text_print(((minute() < 10)? "0" + String(minute()) : String(minute())), 169, 33, WHITE, 8, 0);
//angka jam
//   tft.setCursor(63, 33);
//   tft.print((hour() < 10)?"0" + String(hour()): String(hour()));
ui_text_print(((hour() < 10)? "0" + String(hour()) : String(hour())), 63, 33, WHITE, 8, 0);

//titik dua
//   tft.setCursor(140, 33);
//   tft.print(":");
ui_text_print(":", 140, 33, WHITE, 8, 0);
  
//hari
  text_align_center(weekday_to_string(),100,BLUE,2);
  //tanggal
  tft.setFont(&FreeSansBold12pt7b);
  text_align_center(date_to_string(),137,BLUE,1);
  tft.setFont();
  tft.setTextSize(2);
  //log alarm
  tft.drawBitmap(32, 182, image_clock_alarm_bits, 15, 16, 0xFFFF);
  tft.drawRect(26, 178, 92, 24, ((alarm_is_on)?WHITE:BLUE));
  tft.setCursor(55, 183);
  if(xSemaphoreTake(xprefs,portMAX_DELAY)==pdTRUE){
      settingPrefs.begin("alarm",true);
      uint8_t ah = settingPrefs.getUChar("alarm_hour",0);
      uint8_t am = settingPrefs.getUChar("alarm_minute",0);
      settingPrefs.end();
      tft.printf("%02d:%02d",ah,am);
      xSemaphoreGive(xprefs);
    }

  tft.drawRect(128, 178, 78, 24, BLUE);
  tft.setCursor(157, 183);
  tft.print("99");
  tft.setCursor(190, 183);
  tft.print("C");
  tft.drawBitmap(134, 182, image_weather_temperature_bits, 16, 16, 0xFFFF);
  tft.setTextSize(1);
  tft.setCursor(182, 186);
  tft.print("o");

  tft.drawBitmap(223, 182, image_weather_humidity_bits, 11, 16, 0xFFFF);
  tft.drawRect(216, 178, 78, 24, BLUE);
  tft.setTextSize(2);
  tft.setCursor(241, 183);
  tft.print("99");
  tft.setCursor(268, 183);
  tft.print("%");

  //navbar
  String x[] = {"0","0","0","0","MENU PROGRAM"};
  app_ui_navbar(1,x);
}