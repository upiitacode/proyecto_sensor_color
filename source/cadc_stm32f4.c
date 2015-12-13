#include "cadc_stm32f4.h"
#include "stm32f4xx.h"

void cadc_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// Cofigure PinA0(AN0)
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin = GPIO_Pin_0;
	myGPIO.GPIO_Mode= GPIO_Mode_AN;
	GPIO_Init(GPIOA,&myGPIO);

	//GPIO
	ADC_InitTypeDef myADC;
	ADC_StructInit(&myADC);
	myADC.ADC_ContinuousConvMode =  DISABLE;
	myADC.ADC_DataAlign = ADC_DataAlign_Right;
	myADC.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	myADC.ADC_NbrOfConversion = 0x0;
	myADC.ADC_Resolution = ADC_Resolution_12b;
	myADC.ADC_ScanConvMode = ENABLE;
	ADC_Init(ADC1,&myADC);

	ADC_InjectedChannelConfig(ADC1, ADC_Channel_0,1,ADC_SampleTime_112Cycles);
	ADC_InjectedSequencerLengthConfig(ADC1,1);
	ADC_ExternalTrigInjectedConvEdgeConfig(ADC1,ADC_ExternalTrigInjecConvEdge_None);

	ADC_Cmd(ADC1,ENABLE);
}

uint16_t cadc_getDataInjected1(void){
	ADC_ClearFlag(ADC1,ADC_FLAG_JEOC);
	ADC_SoftwareStartInjectedConv(ADC1);
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_JEOC) == RESET);
	return ADC_GetInjectedConversionValue(ADC1,ADC_InjectedChannel_1);
}
