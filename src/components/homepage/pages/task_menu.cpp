#include <Arduino.h>
#include <FreeRTOSConfig.h>
#include <ui/ui.h>
#include <TimeLib.h>
#include "pages.h"
#include "components/button/button.h"
#include "tasks/tasks.h" //semua fungsi task

uint8_t     task_menu_pointer  = 0; //aplikasi di menu pilihan task yang di pilih sekarang
void        (*task_list_function[])(void*) = {wifi_task}; //array berisi list pointer ke task/program langusng
String      task_list_name[] = {"WiFi Scan","bbbbbb","ccccc"}; //array berisi list nama nama tiap program
uint8_t     task_total = 3; //total keseluruhan program yang akan di tampilkan di list
bool        changed = false; //bernilai true selama tombol di tekan dan belum di lepas
uint8_t     task_pointer_now = 0; //task pilihan sekarang



void select_task(){
    uint8_t btn = button_now();
    if(btn && !changed){
        changed = true;
        if((btn==2 && (task_pointer_now > 0)) || (btn==4 && (task_pointer_now < task_total-1))){
            //hapus higlight pilihan sebelumnya
            ui_graphic_rectagle(0, 30+(task_pointer_now*22), 320, 23, BLACK, 1);
            ui_graphic_rectagle(0, 30+(task_pointer_now*22), 320, 23, BLUE, 0);
            ui_text_print(task_list_name[task_pointer_now],12, 34+(task_pointer_now*22), WHITE, 2, 0);
            
            task_pointer_now += (btn==2)? -1 : 1;

            //higlight pilihan sekarang
            ui_graphic_rectagle(0, 30+(task_pointer_now*22), 320, 23, BLACK, 1);
            ui_graphic_rectagle(0, 30+(task_pointer_now*22), 320, 23, BLUE, 1);
            ui_text_print(task_list_name[task_pointer_now],12, 34+(task_pointer_now*22), WHITE, 2, 0);
        }
    }else if(!btn && changed){
        changed = false;
    }
}


void task_menu_setup(){
    ui_screen_fill(BLACK);

    //menu list
    for(int i = 0; i < task_total ; i++ ){
        ui_graphic_rectagle(0, 30+(i*22), 320, 23, BLUE, 0);
        ui_text_print(task_list_name[i],12, 34+(i*22), WHITE, 2, 0);
    }

    //header
    ui_graphic_rectagle(0, 0, 320, 23, BLUE, 1);
    ui_text_print("PROGRAM MENU", 89, 5, BLACK, 2, 0);

}

void task_menu_page(bool &rendered){
    //setup  function
    if(!rendered){
        rendered = true;
        task_menu_setup();
    }

    //loop
    select_task();
    
    //jalankan task ketika di pilih
    if(button_now() == 3){
        xTaskCreate(task_list_function[task_pointer_now],task_list_name[task_pointer_now].c_str(),4092,nullptr,1,NULL);
        vTaskDelete(NULL);
    }


}