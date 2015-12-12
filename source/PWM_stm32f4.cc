#include "PWM_stm32f4.h"
#include "pwm_stm32.h"

PWM_TIMER2_CH1::PWM_TIMER2_CH1(int prescaler, int autoreload){
	TIMER2_CH2_PWM_Init(prescaler,autoreload);
	this->autoreload = autoreload;
	this->prescaler = prescaler;
}

void PWM_TIMER2_CH1::setDutyCycle(float dutyCycle){
	TIMER2_CH2_PWM_SetDutyCycle(dutyCycle,this->autoreload);
}

float PWM_TIMER2_CH1::getPeriod(void){
	return 0;
}