#include "MainApp.h"
#include "cmsis_os.h"				//ARM::CMSIS:RTOS:Keil RTX
#include "Servo.h"

void MainApp::main(PWM* pwm){
	pwm->setDutyCycle(50.0);
	while(1){
	}
}
