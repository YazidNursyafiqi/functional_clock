#include <Arduino.h>
#include "button.h"

//tombol yang di tekan sekarang
uint8_t button_now = 0;

//deklarasikan semua pin button
#define BTN_LEFT 34
#define BTN_UP 35
#define BTN_MID 32
#define BTN_DOWN 33
#define BTN_RIGHT 25

#define BTN_REFRESH_RATE_MS 100 //durasi update status button per satuan milidetik(ms) 


void button_task(void *param){
    //setup semua pin input
    pinMode(BTN_LEFT,INPUT);
    pinMode(BTN_UP,INPUT);
    pinMode(BTN_MID,INPUT);
    pinMode(BTN_DOWN,INPUT);
    pinMode(BTN_RIGHT,INPUT);
    
    while(true){
        //deklarasi array berisi status ditekan tiap tombol
        bool btn_now[] = {digitalRead(BTN_LEFT),digitalRead(BTN_UP),digitalRead(BTN_MID),digitalRead(BTN_DOWN),digitalRead(BTN_RIGHT)};   

        //iterasi array diatas untuk menentukan tombol mana yang di tekan sekarang
        /*menggunakan pengecekan linear dari posisi tombol 1, yang berarti ketika ada 2 atau
        lebih tombol di tekan secara bersamaan maka yang valid adalah tombol dengan 
        urutan paling awal (dari indeks 0)*/

        for(int i = 0 ; i < 5 ; i++){
            if(btn_now[i]){
                button_now = i+1;
                break;
            }else{
                button_now = 0;
            }
        }

        Serial.printf("Button: %d \n",button_now);
        vTaskDelay(BTN_REFRESH_RATE_MS / portTICK_PERIOD_MS);
    }
}