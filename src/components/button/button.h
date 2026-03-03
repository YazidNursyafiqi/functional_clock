#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include "freertos/semphr.h"


void button_task(void *param); //task yang memeriksa button

extern uint8_t button_now(); //return tombol yang sekarang di tekan
extern bool button_pressed_first; //hanya true pada awal tombol di tekan,
extern SemaphoreHandle_t xbutton; //mutex untuk button

#endif