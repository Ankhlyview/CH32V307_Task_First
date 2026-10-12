#ifndef __MYMENU_H
#define __MYMENU_H
#include "zf_common_headfile.h"
typedef struct
{
    uint32_t magic;

    // LED
    uint8    led_level;
    uint32   led_period;
    uint32   pit_is_able;

    // PWM ·äÃùÆ÷
    uint8    pwm_is_able;
    uint32   pwm_freq;
    uint32   pwm_duty;

    // ÆÁÄ»
    uint32   screen_color;
    uint32   charater_color;
} params_mymenu;

#define LED_Pin              D1
#define LED_PIT_Pin          A15
#define PWM_Pin              TIM1_PWM_MAP0_CH1_A8

#define FLASH_Sector         63
#define FLASH_Page           0
#define PARAMS_Magic         0xA5A5A5A5

#define COLOR_LIST_Count     7
extern const uint16 color_list[COLOR_LIST_COUNT];




#endif