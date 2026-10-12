#include "Key.h"

// 全局变量定义
volatile uint8 key_current = KEY_NONE;
volatile uint8 key_pressed_flag = 0;

// 内部辅助变量
static volatile uint8 key_last_raw = 0;
static volatile uint8 key_count = 0;

// 1ms 定时器中断中调用
void key_scan_in_isr(void)
{
    uint8 raw = (gpio_get_level(KEY_A2_PIN) << 2) |
                (gpio_get_level(KEY_A1_PIN) << 1) |
                (gpio_get_level(KEY_A0_PIN));
    raw = (~raw) & 0x07;   // 取反，得到 0~7

    // 消抖：连续 10 次采样相同才稳定
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