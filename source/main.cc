#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "PWM_stm32f4.h"
#include "SerialStream_stm32f4.h"
#include "cadc_stm32f4.h"
#include "MainApp.h"

void tarea1(void const * arguments); //tarea 1
osThreadId  tarea1ID;	//identificador del hilo tarea 1
osThreadDef (tarea1,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void osInitAll(void);
void tarea1Init(void);//funcion que iniciliza la tarea1

int main(){
	// Init OS
	osInitAll();
	// HW configuration
	SerialStream* serial  = new SerialUSART2(9600);
	PWM* pwm = new PWM_TIMER2_CH1(15,1000); //  1000us -> a 1KHz
	cadc_init();
	//Usar application
	serial->printf("\nHello World\n");
	MainApp::main(pwm, serial);
	return 0;
}
void osInitAll(void){
	osKernelInitialize();
	tarea1Init();
	osKernelStart();
}

void tarea1Init(void){
	tarea1ID= osThreadCreate(osThread(tarea1),NULL);
}

void tarea1(void const * arguments){
	while(1){
		osDelay(1000);
	}
}
