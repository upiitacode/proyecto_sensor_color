#include "Servo.h"

Servo::Servo(PWM* pwm, int initialPosition){
	this->pwm = pwm;
	this->setPosition(initialPosition);
}

void Servo::setPosition(float position){
	float dutyCycle= ((52.0/180.0)*position) + 32.0;
	pwm->setDutyCycle(dutyCycle);
}