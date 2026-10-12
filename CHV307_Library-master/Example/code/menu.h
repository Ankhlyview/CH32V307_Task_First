#ifndef __MENU_H
#define __MENU_H

#include "zf_common_headfile.h"

// ==================== 参数结构体 ====================
typedef struct
{
    uint32_t magic_;

    // LED
    uint8    led_level_;       // D1 LED 开关
    uint32   led_period_;      // A15 LED 闪烁周期（1ms 中断次数）
    uint32   pit_is_able_;     // A15 LED 闪烁使能

    // PWM 蜂鸣器
    uint8    pwm_is_able_;     // 蜂鸣器开关
    uint32   pwm_freq_;        // 频率 Hz
    uint32   pwm_duty_;        // 占空比 0~10000

    // 屏幕
    uint32   screen_color_;    // 背景色
    uint32   charater_color_;  // 字体色
} params_menu_;

// ==================== 引脚定义 ====================
#define LED_PIN              D1
#define LED_PIT_PIN          A15
#define PWM_PIN              TIM1_PWM_MAP0_CH1_A8
#define KEY_A0_PIN           D8
#define KEY_A1_PIN           B12
#define KEY_A2_PIN           B14
#define ST7735S_SCL_PIN      B13
#define ST7735S_SDA_PIN      B15
#define ST7735S_RES_PIN      B7
#define ST7735S_DC_PIN       D7
#define ST7735S_CS_PIN       D4
#define ST7735S_BL_PIN       D0

// ==================== Flash ====================
#define FLASH_SECTOR         63
#define FLASH_PAGE           0
#define PARAMS_MAGIC         0xA5A5A5A5

// ==================== 颜色列表 ====================
#define COLOR_LIST_COUNT     7
extern const uint16 color_list[COLOR_LIST_COUNT];

// ==================== 全局参数 ====================
extern params_menu_ params;

// ==================== 参数接口 ====================
void params_save(void);
void params_load(void);
void params_reset(void);
void params_apply_all(void);

// ==================== 菜单接口 ====================
void menu_init(void);
void menu_handle_key(uint8 key);
void menu_draw(void);

#endif