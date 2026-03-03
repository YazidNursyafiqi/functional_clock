#include <Arduino.h>
#include <TimeLib.h>
//rtc library
#include <Ds1302.h>

#include "time.h"

const uint8_t PIN_RST = 22;
const uint8_t PIN_CLK = 21;
const uint8_t PIN_DAT = 19;

// Inisialisasi library DS1302
Ds1302 rtc(PIN_RST, PIN_CLK, PIN_DAT);

// Fungsi sinkron TimeLib dari RTC
time_t getRTCTime() {
  Ds1302::DateTime dt;
  rtc.getDateTime(&dt);
  // konversi ke time_t
  tmElements_t tm;
  tm.Year = dt.year + 2000 - 1970;
  tm.Month = dt.month;
  tm.Day = dt.day;
  tm.Hour = dt.hour;
  tm.Minute = dt.minute;
  tm.Second = dt.second;
  return makeTime(tm);
}


void time_setup(){
    rtc.init();
    
    // Ds1302::DateTime dt;
    // dt.year = 26;      // 2026 -> cukup 2 digit
    // dt.month = 2;
    // dt.day = 28;
    // dt.hour = 1;
    // dt.minute = 45;
    // dt.second = 0;
    // dt.dow = 6;  
    // rtc.setDateTime(&dt);

    setSyncProvider(getRTCTime);
}

void time_debug(){
  Ds1302::DateTime dt;
  rtc.getDateTime(&dt);
  Serial.printf("time: %d : %d : %d",dt.hour,dt.minute,dt.second);
  delay(1500);
}

