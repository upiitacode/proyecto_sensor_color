#include "led.h"
#include "stm32f4xx.h"
void led_init(void){
	RCC->AHB1ENR= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER&=~(GPIO_MODER_MODER5);
	GPIOA->MODER|= GPIO_MODER_MODER5_0;
	GPIOA->ODR|= GPIO_ODR_ODR_5;

}