#include "zf_common_headfile.h"
// 用的TIM1和A8口


void pwm_init_(void)
{
    pwm_init(TIM1_PWM_MAP0_CH1_A8,50,5000);
}

void pwm_change_(uint32 freq,uint32 duty)
{
    pwm_set_freq(TIM1_PWM_MAP0_CH1_A8,freq,duty);
}

//驱动的话就直接上一个蜂鸣器就行了吧