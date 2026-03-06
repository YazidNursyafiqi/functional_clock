#include <Arduino.h>
#include <WiFi.h>
#include "components/button/button.h"
#include "ui/ui.h" 
#include "tasks/tasks.h"

void wifi_task(void *param){
    /*--------------setup--------------*/
    ui_screen_fill(BLACK);
    //header
    ui_graphic_rectagle(0, 0, 320, 23, BLUE, 1);
    text_align_center("WIFI SCANNER", 5, BLACK, 2, 0);

    //wifi setup
    WiFi.mode(WIFI_STA);

    
    /*--------------loop--------------*/
    while(true){
        uint8_t  n = WiFi.scanNetworks();
        //refresh list
        ui_graphic_rectagle(0, 24, 320, 216, BLACK, 1);

        if(n < 1){
            //ketika tidak ada wifi ditemukan
            text_align_center("Tidak ada wifi terdeteksi", 30, RED, 2, 0);
        }else{
            //wifi list
            for(int i = 0; i < n ; i++ ){
                ui_graphic_rectagle(0, 30+(i*22), 320, 23, BLUE, 0);
                ui_text_print(WiFi.SSID(i),12, 34+(i*22), WHITE, 2, 0);
            }
        }

        vTaskDelay(2000/portTICK_PERIOD_MS);
    }
    
}


