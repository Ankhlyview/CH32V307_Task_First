#ifndef __KEY_H
#define __KEY_H

#include "zf_common_headfile.h"

// 引脚定义
#define KEY_A0_PIN   D8
#define KEY_A1_PIN   B12
#define KEY_A2_PIN   B14

// 按键枚举
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

// 全局变量（只声明）
extern volatile uint8 key_current;
extern volatile uint8 key_pressed_flag;

// 函数声明
void key_scan_in_isr(void);

#endif