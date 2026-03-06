#include <Arduino.h>
#include <TimeLib.h>
#include "homepage.h"
#include "components/display/display.h"
#include "components/button/button.h"

//import ui elements


//import semua page
#include "pages/pages.h"

uint8_t     page_now = 0;   //untuk menyimpan informasi di halaman apa sekarang (default 0=> home screen)
uint8_t     page_total = 2;   //jumlah page

bool        booting = true; //true ketika awal booting
bool        rendered = false; //true ketika page awal di render (berfungsi untuk menjalankan fungsi sekali render pada sebuah page)
void        (*page_list[])(bool&) = {dashboard_page,task_menu_page}; //list fungsi tiap tiap page | parameternya adalah reference ke value rendered
bool        page_changed = false; //bernilai tru selagi tombol masih di tekan dan false ketika tombol sudah di lepas


void select_page(){
    uint8_t btn = button_now();
    if(btn &&  !page_changed){ //jika rtombol di tekan dan page belum diubah
        page_changed = true;
        //switch case button kanan atau kiri untuk mengubah variabel page
        //1 : decrement | 5 : increment
        switch(btn){
            case 1:
                if(page_now > 0){ //mencegah pointer page menjadi mines
                    page_now--;
                    rendered = false;
                }
                break;
                case 5:
                if(page_now < page_total-1){ //mencegah pointer melampaui batas jumlah page
                    page_now++;
                    rendered = false;
                }
                break;
        }

    }else if(!btn && page_changed){
        page_changed = false;
    }
}

void homepage_task(void *param){
    //setup
    if(booting){
        booting = false;
        
        /* -----------------------------debugging---------------------------------- */
        Serial.printf("booting\n");
        
        vTaskDelay(1500 / portTICK_PERIOD_MS);
    }
    
    //loop
    while (true){
        page_list[page_now](rendered); //hanya mengeksekusi fungsi page sesuai nomor page sekarang
        
        select_page(); //fungsi untuk memeriksa kondisi tombol dan handle pergantian page
        
        vTaskDelay(100 / portTICK_PERIOD_MS);
        
        /* -----------------------------debugging---------------------------------- */
        //Serial.printf("page: %d , button: %d\n",page_now,button_now());
        Serial.printf("%d : %d : %d / day : %d month : %d year : %d",hour(),minute(),second(),day(),month(),year());
    }
}
