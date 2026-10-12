#ifndef __MENU_H
#define __MENU_H

#include "zf_common_headfile.h"

// ==================== 参数结构体 ====================
typedef struct
{
    uint32_t magic_;

    // LED
    uint8    led_level_;
    uint32   led_period_;
    uint32   pit_is_able_;

    // PWM 蜂鸣器
    uint8    pwm_is_able_;
    uint32   pwm_freq_;
    uint32   pwm_duty_;

    // 屏幕
    uint32   screen_color_;
    uint32   charater_color_;
} params_menu_;

// ==================== 引脚定义 ====================
#define LED_PIN              D1
#define LED_PIT_PIN          A15
#define PWM_PIN              TIM1_PWM_MAP0_CH1_A8

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