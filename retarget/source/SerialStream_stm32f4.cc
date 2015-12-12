#include "SerialStream_stm32f4.h"
#include "retarget_stm32f4.h"     // Device header

SerialUSART2::SerialUSART2(int baudrate){
	USART2_init(baudrate);
}


void SerialUSART2::sendChar(char ch){
	USART2_sendChar(ch);
}

char SerialUSART2::getChar(void){
	return USART2_getChar();
}

SerialUSART1::SerialUSART1(int baudrate){
	USART1_init(baudrate);
}


void SerialUSART1::sendChar(char ch){
	USART1_sendChar(ch);
}

char SerialUSART1::getChar(void){
	return USART1_getChar();
}

