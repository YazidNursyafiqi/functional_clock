#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

void button_task(void *param); //task yang memeriksa button

extern uint8_t button_now; //tombol yang sekarang di tekan

#endif