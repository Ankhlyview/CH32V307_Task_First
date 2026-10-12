#include "zf_common_headfile.h"
// 我这里想到的是用GPIO的外部中断来进行这个操作，嘛，ai告诉我






// //这里我们假设常态的按键时高电平,而按下按键是低电平
// // 这个数据模式得看最后的板子的连接方式了
// void key_init_(void)
// {
//     gpio_init(Key_Pin,GPI,0,GPI_PULL_UP);
// }

// // 读取按键的状态(这里得看是否有电容来滤波)
// // 这里是用按一下是一下的方式，就是按下和松开是一个进程，用最笨的方式吧
// // 这个就是得在一个循环结束后将这个自己设置的标志位清零
// uint8 key_read_deal_(void)
// {
//     uint8 is_key = 0;
//     if(gpio_get_level(Key_Pin) == 0)
//     {
//         system_delay_ms(20);
//         while(gpio_get_level(Key_Pin) == 0);
//         system_delay_ms(20);
//         is_key = 1;
//     }
//     return is_key;
// }

// uint8 key_read_else_deal_(uint8 num)
// {
//     uint8 is_key = 0;
//     if(gpio_get_level(Key_Pin) == 1 && num == 1)
//     {
//         system_delay_ms(20);
//         if(gpio_get_level(Key_Pin) == 1)
//             is_key = 0;
//     }
//     if(gpio_get_level(Key_Pin) == 0 && num == 0)
//     {
//         system_delay_ms(20);
//         if(gpio_get_level(Key_Pin) == 0)
//             is_key = 1;
//     }
//     return is_key;
// }