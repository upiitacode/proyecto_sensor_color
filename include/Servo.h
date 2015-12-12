#ifndef _SERVO_H
#define _SERVO_H

#include "PWM.h"

class Servo{
	private:
		PWM* pwm;
	public: 
		Servo(PWM* pwm,int initialPosition= 0);
		void setPosition(float position);
	
};
#endif// _SERVO_H