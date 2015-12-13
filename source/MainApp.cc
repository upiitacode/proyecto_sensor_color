#include "MainApp.h"
#include "cmsis_os.h"				//ARM::CMSIS:RTOS:Keil RTX
#include "Servo.h"
#include "cadc_stm32f4.h"
#include "stm32f4xx.h"

#define RGB_COLOR_BLACK 0
#define RGB_COLOR_RED 1
#define RGB_COLOR_GREEN 2
#define RGB_COLOR_BLUE 3

float getVoltage(void);
void rgb_led_init(void);
void rgb_led_setColor(int color);

#define WAIT_TIME 100

void MainApp::main(PWM* pwm, SerialStream* serial){
	float volt_red;
	float volt_green;
	float volt_blue;

	rgb_led_init();
	pwm->setDutyCycle(50.0);

	while(1){
		rgb_led_setColor(RGB_COLOR_RED);
		osDelay(WAIT_TIME);
		volt_red =  getVoltage();
		volt_red =  getVoltage()/0.8;

		rgb_led_setColor(RGB_COLOR_GREEN);
		osDelay(WAIT_TIME);
		volt_green =  getVoltage();
		volt_green =  getVoltage()/0.35;

		rgb_led_setColor(RGB_COLOR_BLUE);
		osDelay(WAIT_TIME);
		volt_blue =  getVoltage();
		volt_blue =  getVoltage()/0.18;
		serial->printf("R:%5.1f, G:%5.1f, B:%5.1f",volt_red,volt_green,volt_blue);
		if((volt_red > 300) && (volt_green < 100) &&(volt_blue < 200)){
			serial->printf(", color = red\n");
		}else if((volt_red < 300) && (volt_green > 100) &&(volt_blue < 200)){
			serial->printf(", color = green\n");
		}else if((volt_red < 300) && (volt_green > 100) &&(volt_blue > 200)){
			serial->printf(", color = blue\n");
		}else if((volt_red > 300) && (volt_green > 100) &&(volt_blue > 200)){
			serial->printf(", color = white\n");
		}else if((volt_red < 300) && (volt_green < 100) &&(volt_blue < 200)){
			serial->printf(", color = black\n");
		}else{
			serial->printf(", color = none\n");
		}
	}
}

#define N_SAMPLES 50
float getVoltage(void){
	int accu = 0;
	uint16_t adc_reading;
	for(int i = 0; i < N_SAMPLES; i++){
		adc_reading = cadc_getDataInjected1();
		accu += adc_reading;
	}

	accu /= N_SAMPLES;

	return accu * (3.3/4095.0) * 1000;
}

void rgb_led_init(void){
	//LEDS RGB PA[6..8]
	RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_GPIOAEN,ENABLE);
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin=GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	myGPIO.GPIO_Mode=GPIO_Mode_OUT;
	myGPIO.GPIO_Speed=GPIO_Speed_25MHz;
	rgb_led_setColor(0);
	GPIO_Init(GPIOA,&myGPIO);
}

// R=D7=A8, G=D11=A7, B=D12=A6
void rgb_led_setColor(int color){
	if(color == RGB_COLOR_BLACK){
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
	}else if(color == RGB_COLOR_RED){
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	}else if(color == RGB_COLOR_GREEN){
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
	}else if(color == RGB_COLOR_BLUE){
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
	}
}
