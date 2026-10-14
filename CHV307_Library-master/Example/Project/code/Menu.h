#ifndef __MENU_H
#define __MENU_H

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
} params_menu;


#define LED_PIN              D1
#define LED_PIT_PIN          A15
#define PWM_PIN              TIM1_PWM_MAP0_CH1_A8


#define FLASH_SECTOR         63
#define FLASH_PAGE           0
#define PARAMS_MAGIC         0xA5A5A5A5

#define COLOR_LIST_COUNT     8
extern const uint16 color_list[COLOR_LIST_COUNT];

extern params_menu params;
void params_save(void);
void params_load(void);
void params_reset(void);
void params_apply(void);
void menu_init(void);
void menu_draw(void);
void menu_handle_key(uint8 key);


#endif