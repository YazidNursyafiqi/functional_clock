#include <Arduino.h>
#include <ui/ui.h>
#include <TimeLib.h>
#include "pages.h"

String day_string[] = {"MINGGU","SENIN","SELASA","RABU","KAMIS","JUMAT","SABTU"};
String month_string[] = {"Januari","Februari","Maret","April","Mei","Juni","Juli","Agustus","September","Oktober","November","Desember"};

//simpan semua bitmap
static const unsigned char PROGMEM image_clock_alarm_bits[] = {0x79,0x3c,0xb3,0x9a,0xed,0x6e,0xd0,0x16,0xa0,0x0a,0x41,0x04,0x41,0x04,0x81,0x02,0xc1,0x06,0x82,0x02,0x44,0x04,0x48,0x04,0x20,0x08,0x10,0x10,0x2d,0x68,0x43,0x84};
static const unsigned char PROGMEM image_weather_humidity_bits[] = {0x04,0x00,0x04,0x00,0x0c,0x00,0x0e,0x00,0x1e,0x00,0x1f,0x00,0x3f,0x80,0x3f,0x80,0x7e,0xc0,0x7f,0x40,0xff,0x60,0xff,0xe0,0x7f,0xc0,0x7f,0xc0,0x3f,0x80,0x0f,0x00};
static const unsigned char PROGMEM image_weather_temperature_bits[] = {0x1c,0x00,0x22,0x02,0x2b,0x05,0x2a,0x02,0x2b,0x38,0x2a,0x60,0x2b,0x40,0x2a,0x40,0x2a,0x60,0x49,0x38,0x9c,0x80,0xae,0x80,0xbe,0x80,0x9c,0x80,0x41,0x00,0x3e,0x00};

int x = 0;

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
  text_align_center(day_string[weekday()-1],100,BLUE,2,0);
  Serial.println(day());
  //tanggal
  text_align_center((String(day()) + " " + month_string[month()-1] + " " + String(year())),137,BLUE,1,1);

  // tft.drawBitmap(32, 182, image_clock_alarm_bits, 15, 16, 0xFFFF);
  ui_graphic_bitmap(32,182,image_clock_alarm_bits,15,16,WHITE);

  //tft.drawRect(26, 178, 92, 24, ((alarm_is_on)?WHITE:BLUE));
  ui_graphic_rectagle(26,178,92,24,WHITE,0);
  
  // tft.setCursor(55, 183);
    // if(xSemaphoreTake(xprefs,portMAX_DELAY)==pdTRUE){
    //     settingPrefs.begin("alarm",true);
    //     uint8_t ah = settingPrefs.getUChar("alarm_hour",0);
    //     uint8_t am = settingPrefs.getUChar("alarm_minute",0);
    //     settingPrefs.end();
    //     tft.printf("%02d:%02d",ah,am);
    //     xSemaphoreGive(xprefs);
    //   }

    //tft.drawRect(128, 178, 78, 24, BLUE);
  ui_graphic_rectagle(128,178,78, 24, BLUE,0);
  

    // tft.setCursor(157, 183);
    // tft.print("99");
    // tft.setCursor(190, 183);
    // tft.print("C");
    ui_text_print("99", 157, 183, WHITE, 1, 0);
    ui_text_print("C", 190, 183, WHITE, 1, 0);

  //   tft.drawBitmap(134, 182, image_weather_temperature_bits, 16, 16, 0xFFFF);
  //   tft.setTextSize(1);
  //   tft.setCursor(182, 186);
  //   tft.print("o");

  //   tft.drawBitmap(223, 182, image_weather_humidity_bits, 11, 16, 0xFFFF);
  //   tft.drawRect(216, 178, 78, 24, BLUE);
  //   tft.setTextSize(2);
  //   tft.setCursor(241, 183);
  //   tft.print("99");
  //   tft.setCursor(268, 183);
  //   tft.print("%");

  //   //navbar
  //   String x[] = {"0","0","0","0","MENU PROGRAM"};
  //   app_ui_navbar(1,x);
}

void dashboard_page(bool &rendered){

    //setup  function
    if(!rendered){
        rendered = true;
        home_screen_setup(); 
    }



    //loop function
    x++;
    Serial.println(x);
}