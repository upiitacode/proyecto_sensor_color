#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "PWM_stm32f4.h"
#include "MainApp.h"

void tarea1(void const * arguments); //tarea 1
osThreadId  tarea1ID;	//identificador del hilo tarea 1
osThreadDef (tarea1,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea2(void const * arguments); //tarea 2
osThreadId  tarea2ID;	//identificador del hilo  tarea 2
osThreadDef (tarea2,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea1Init(void);//funcion que iniciliza la tarea1
void tarea2Init(void);//funcion que iniciliza la tarea1

void osInitall(void);


int main(){
	//Usar application
	//osInitAll();
	PWM* pwm = new PWM_TIMER2_CH1(15,1999); //  2000us -> a 500Hz
	MainApp::main(pwm);
	return 0;
}
void osInitAll(void){
	osKernelInitialize();
	tarea1Init();
	tarea2Init();
	osKernelStart();
}

void tarea1Init(void){
	tarea1ID= osThreadCreate(osThread(tarea1),NULL);
}

void tarea2Init(void){
	tarea2ID= osThreadCreate(osThread(tarea2),NULL);
}

void tarea1(void const * arguments){
	while(1){
		osDelay(1000);
	}
}

void tarea2(void const * arguments){
	while(1){
		osDelay(10);
	}
}
