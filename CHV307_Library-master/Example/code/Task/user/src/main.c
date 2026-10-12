#include "zf_common_headfile.h"
#include "key.h"
#include "menu.h"
#include "st7735s.h"

int main(void)
{
    clock_init(SYSTEM_CLOCK_120M);
    debug_init();

    // 1. 从 Flash 加载参数
    params_load();
    params_reset();          // 恢复默认并写入 Flash
    params_apply_all();      // 应用到硬件
    // 2. LED 初始化
    gpio_init(LED_PIN,     GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED_PIT_PIN, GPO, 0, GPO_PUSH_PULL);
    gpio_set_level(LED_PIN, params.led_level_ ? 1 : 0);

    // 3. PWM 蜂鸣器
    pwm_init(PWM_PIN, params.pwm_freq_, params.pwm_duty_);
    if (!params.pwm_is_able_) pwm_set_duty(PWM_PIN, 0);

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

