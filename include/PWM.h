#ifndef _PWM_H
#define _PWM_H

class PWM{
	public:
		virtual void setDutyCycle(float) = 0;
		virtual float getPeriod(void) = 0;
};

#endif// _PWM_H