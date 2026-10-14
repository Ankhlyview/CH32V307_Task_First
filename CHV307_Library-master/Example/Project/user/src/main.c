#include "zf_common_headfile.h"
#include "Key.h"
#include "Menu.h"
#include "St7735s.h"

int main(void)
{
    clock_init(SYSTEM_CLOCK_120M);
    debug_init();

    params_load();
    params_reset();      
    params_apply();     

    gpio_init(LED_PIN,     GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED_PIT_PIN, GPO, 0, GPO_PUSH_PULL);
    gpio_set_level(LED_PIN, params.led_level ? 1 : 0);

    pwm_init(PWM_PIN, params.pwm_freq, params.pwm_duty);
    if (!params.pwm_is_able) pwm_set_duty(PWM_PIN, 0);

    // 4. 按键引脚
    gpio_init(KEY_A0_PIN, GPI, 0, GPI_PULL_UP);
    gpio_init(KEY_A1_PIN, GPI, 0, GPI_PULL_UP);
    gpio_init(KEY_A2_PIN, GPI, 0, GPI_PULL_UP);

    // 5. 屏幕初始化
    st7735s_init();

    // 6. 1ms 定时器中断
    pit_init(TIM3_PIT, 120000);

    // 7. 菜单
    menu_init();
    menu_draw();

    while (1)
    {
        if (key_pressed_flag)
        {
            key_pressed_flag = 0;
            menu_handle_key(key_current);
            menu_draw();
        }
    }
}

