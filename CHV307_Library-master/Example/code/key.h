#ifndef __KEY_H
#define __KEY_H

#include "zf_common_headfile.h"
#include "menu.h"
// #define KEY_A0_PIN   KEY_A0_Pin
// #define KEY_A1_PIN   KEY_A1_Pin
// #define KEY_A2_PIN   KEY_A2_Pin


typedef enum {
    KEY_NONE = 0,
    KEY_L,
    KEY_D,
    KEY_U,
    KEY_KEY1,
    KEY_R,
    KEY_M,
    KEY_KEY2
} key_enum;

extern volatile uint8 key_current;
extern volatile uint8 key_pressed_flag;

void key_scan_in_isr(void);

#endif