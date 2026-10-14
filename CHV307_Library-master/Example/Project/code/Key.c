#include "Key.h"


volatile uint8 key_current = KEY_NONE;
volatile uint8 key_pressed_flag = 0;
static volatile uint8 key_last_raw = 0;
static volatile uint8 key_count = 0;

// 轮询模式:(我也是魔了
void key_scan_in_isr(void)
{
    uint8 raw = (gpio_get_level(KEY_A2_PIN) << 2) |(gpio_get_level(KEY_A1_PIN) << 1) |(gpio_get_level(KEY_A0_PIN));
    raw = (~raw) & 0x07;

    if (raw != key_last_raw) {
        key_count = 0;
        key_last_raw = raw;
    } else {
        if (key_count < 10) key_count++;
    }

    if (key_count == 10) {
        if (raw != key_current) {
            key_current = raw;
            if (raw != KEY_NONE) {
                key_pressed_flag = 1;
            }
        }
    }
}