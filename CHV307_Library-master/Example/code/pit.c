#include "zf_common_headfile.h"
#define GPIO_Pin A0 

uint32 period = 114514;

void pit_init_(void)
{
    pit_init(TIM3_PIT,period);
    pit_enable(TIM3_PIT);
    gpio_init(GPIO_Pin,GPO,0,GPO_PUSH_PULL);
}

void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
        gpio_toggle_level(GPIO_Pin);
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    }
}