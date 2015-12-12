#ifndef _PWM_STM32F4_H
#define _PWM_STM32F4_H

#include "PWM.h"

class PWM_TIMER2_CH1 : public PWM{
	private:
		int autoreload;
		int prescaler;
	public:
		PWM_TIMER2_CH1(int prescaler, int autoreload);
		virtual void setDutyCycle(float);
		virtual float getPeriod(void);
};

#endif
