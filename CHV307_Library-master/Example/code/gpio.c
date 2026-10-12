#include "zf_common_headfile.h"

#define GPIO_Pin D1 
// D1,A15,A12,A11,这是四个LED的引脚
// 要输出高电平才能亮

// 这里先配置A0口是推挽输出的口，等板子来了后进行修改
void gpio_init_(void)
{
    gpio_init(GPIO_Pin,GPO,1,GPO_PUSH_PULL);
}

// 这个就是正常的等时间闪烁
void gpio_led_show_(void)
{
    gpio_toggle_level(GPIO_Pin);
    system_delay_ms(1000);
    gpio_toggle_level(GPIO_Pin);
    system_delay_ms(1000);
    
}