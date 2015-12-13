#ifndef _MAINAPP_H
#define _MAINAPP_H
	
#include "PWM.h"
#include "SerialStream.h"

class MainApp{
	public:
		static void main(PWM* pwm, SerialStream* serial);
};

#endif// _MAINAPP_H
